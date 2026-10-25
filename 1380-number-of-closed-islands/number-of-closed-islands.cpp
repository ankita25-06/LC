class Solution {
    void dfs(int r,int c,vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0|| c < 0 || r >= rows || c >= cols || grid[r][c] == 1){
            return;
        }

        grid[r][c] = 1;

        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        for(int r = 0;r<rows;r++){
            for(int c = 0;c<cols;c++){
                if((r == 0 || r == rows-1 || c == 0 || c == cols-1) && grid[r][c] == 0){
                    dfs(r,c,grid);
                }
            }
        }
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    count++;
                    dfs(r, c, grid);
                }
            }
        }

        return count;
    }
};