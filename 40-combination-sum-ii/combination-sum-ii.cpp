class Solution {
private:
    void backtrack(int start, int remaining, const vector<int>& candidates,vector<int>& current, vector<vector<int>>& ans) {
        if (remaining == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
                
            if (candidates[i] > remaining) {
                break;
            }
                
            current.push_back(candidates[i]);
            backtrack(i + 1, remaining - candidates[i], candidates, current, ans);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(0, target, candidates, current, ans);
        return ans;
    }
};