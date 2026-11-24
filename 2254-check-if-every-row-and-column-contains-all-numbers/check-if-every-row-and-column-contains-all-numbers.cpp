class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<bool> seen(n + 1, false);
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (seen[val]) return false;
                seen[val] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            vector<bool> seen(n + 1, false);
            for (int i = 0; i < n; i++) {
                int val = matrix[i][j];
                if (seen[val]) return false;
                seen[val] = true;
            }
        }

        return true;
    }
};