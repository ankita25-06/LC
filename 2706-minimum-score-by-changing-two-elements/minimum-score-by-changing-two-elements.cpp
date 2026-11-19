class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int o1 = nums[n-1]-nums[2];
        int o2 = nums[n-2]-nums[1];
        int o3 = nums[n-3]-nums[0];

        return min({o1,o2,o3});
    }
};