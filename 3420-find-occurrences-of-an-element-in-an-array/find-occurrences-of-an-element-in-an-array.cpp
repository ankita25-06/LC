class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                indices.push_back(i);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            int targetIdx = q - 1;
            if (targetIdx >= 0 && targetIdx < indices.size()) {
                ans.push_back(indices[targetIdx]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};