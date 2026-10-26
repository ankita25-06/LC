class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int valid_islands = 0;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    
                    long long current_sum = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({r, c});
                    visited[r][c] = true;
                    
                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();
                        
                        current_sum += grid[curr_r][curr_c];
                        
                        for (int i = 0; i < 4; i++) {
                            int nr = curr_r + dr[i];
                            int nc = curr_c + dc[i];
                            
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] > 0) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    if (current_sum % k == 0) {
                        valid_islands++;
                    }
                }
            }
        }
        
        return valid_islands;
    }
};