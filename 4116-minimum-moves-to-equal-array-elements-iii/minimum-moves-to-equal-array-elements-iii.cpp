class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(),nums.end());
        int val = nums[nums.size()-1];

        for(int num : nums){
            count += val - num;
        }

        return count;
    }
};