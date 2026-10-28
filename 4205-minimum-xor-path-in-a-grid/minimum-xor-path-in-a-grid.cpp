class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        
        dp[0][0].set(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j].none()) continue;
                
                if (i + 1 < m) {
                    int val = grid[i + 1][j];
                    
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[i][j].test(x)) {
                            dp[i + 1][j].set(x ^ val);
                        }
                    }
                }
                
                if (j + 1 < n) {
                    int val = grid[i][j + 1];
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[i][j].test(x)) {
                            dp[i][j + 1].set(x ^ val);
                        }
                    }
                }
            }
        }
        
        for (int x = 0; x < 1024; ++x) {
            if (dp[m - 1][n - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};