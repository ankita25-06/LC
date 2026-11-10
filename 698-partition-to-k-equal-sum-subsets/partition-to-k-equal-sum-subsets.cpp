class Solution {
    bool backtrack(vector<int>& nums,vector<int>& buckets, int index, int target){
        if(index == nums.size())return true;

        int val = nums[index];

        for(int i = 0;i<buckets.size();i++){
            if (buckets[i] + val <= target) {
                buckets[i] += val;
                if (backtrack(nums, buckets, index + 1, target)) {
                    return true;
                }
                buckets[i] -= val;
            }

            if(buckets[i] == 0)break;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;
        
        int target = totalSum / k;
        
        sort(nums.rbegin(), nums.rend());
        
        if (nums[0] > target) return false;
        
        vector<int> buckets(k, 0);
        return backtrack(nums, buckets, 0, target);
    }
};