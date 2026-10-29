class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> segTree;
    int curPos;

    int dfs1(int u, int p, int d) {
        int size = 1;
        int maxSubtree = 0;
        parent[u] = p;
        depth[u] = d;

        for (int v : adj[u]) {
            if (v != p) {
                int subSize = dfs1(v, u, d + 1);
                size += subSize;
                if (subSize > maxSubtree) {
                    maxSubtree = subSize;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void dfs2(int u, int h, const string& s) {
        head[u] = h;
        pos[u] = curPos++;
        
        updateSegTree(1, 0, n - 1, pos[u], 1 << (s[u] - 'a'));

        if (heavy[u] != -1) {
            dfs2(heavy[u], h, s);
        }

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v, s);
            }
        }
    }

    void updateSegTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            segTree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            updateSegTree(2 * node, start, mid, idx, val);
        else
            updateSegTree(2 * node + 1, mid + 1, end, idx, val);
        segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
    }

    int querySegTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return segTree[node];
        int mid = start + (end - start) / 2;
        return querySegTree(2 * node, start, mid, l, r) ^ 
               querySegTree(2 * node + 1, mid + 1, end, l, r);
    }

    int queryPath(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res ^= querySegTree(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= querySegTree(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        segTree.assign(4 * n, 0);
        curPos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0, s);

        vector<bool> ans;

        for (const auto& q : queries) {
            if (q[0] == 'u') { 
                int u = 0;
                int i = 7;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q[i + 1];
                updateSegTree(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else { 
                int u = 0, v = 0;
                int i = 6;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++;
                while (i < q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }

                int mask = queryPath(u, v);
                
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};