#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        
        auto get_next = [&](int r, int c, int dir) -> pair<int, int> {
            while (r < m && c < n && grid[r][c] == 1) {
                if (dir == 0) {
                    c++;
                    dir = 1;
                } else {
                    r++;
                    dir = 0;
                }
            }
            if (r >= m || c >= n) return {-1, -1}; 
            return {r, c};
        };

        
        vector<vector<pair<int, int>>> go_down(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> go_right(m, vector<pair<int, int>>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    int r = i + 1, c = j;
                    int dir = 0;
                    auto [nr, nc] = get_next(r, c, dir);
                    go_down[i][j] = {nr, nc};
                } else {
                    go_down[i][j] = {-1, -1};
                }

                if (j + 1 < n) {
                    int r = i, c = j + 1;
                    int dir = 1;
                    auto [nr, nc] = get_next(r, c, dir);
                    go_right[i][j] = {nr, nc};
                } else {
                    go_right[i][j] = {-1, -1};
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                auto [next_r_d, next_c_d] = go_down[i][j];
                if (next_r_d != -1 && next_c_d != -1) {
                    dp[next_r_d][next_c_d] = (dp[next_r_d][next_c_d] + dp[i][j]) % MOD;
                }

                auto [next_r_r, next_c_r] = go_right[i][j];
                if (next_r_r != -1 && next_c_r != -1) {
                    dp[next_r_r][next_c_r] = (dp[next_r_r][next_c_r] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};