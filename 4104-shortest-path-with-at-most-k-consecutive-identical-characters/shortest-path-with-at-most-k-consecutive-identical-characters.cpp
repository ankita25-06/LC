class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, -1e18));

        pq.push({0, 0, 1});
        
        vector<vector<bool>> visited(n, vector<bool>(k + 1, false));  

         while (!pq.empty()) {
            auto [w, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return w;
            }

            if (visited[u][count]) continue;
            visited[u][count] = true;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                int next_count;
                if (labels[u] == labels[v]) {
                    next_count = count + 1;
                } else {
                    next_count = 1;
                }

                if (next_count <= k) {
                    if (!visited[v][next_count]) {
                        pq.push({w + weight, v, next_count});
                    }
                }
            }
        }

        return -1;            
    }
};