class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; ++i) {
            origAdj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> lastSeen(26, -1);

        auto findParents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (u == 0) {
                newParent[u] = -1;
            } else if (lastSeen[c] != -1) {
                newParent[u] = lastSeen[c];
            } else {
                newParent[u] = parent[u];
            }

            int prev = lastSeen[c];
            lastSeen[c] = u;

            for (int v : origAdj[u]) {
                self(self, v);
            }

            lastSeen[c] = prev;
        };

        findParents(findParents, 0);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; ++i) {
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto computeSizes = [&](auto& self, int u) -> int {
            int size = 1;
            for (int v : finalAdj[u]) {
                size += self(self, v);
            }
            return ans[u] = size;
        };

        computeSizes(computeSizes, 0);
        return ans;
    }
};