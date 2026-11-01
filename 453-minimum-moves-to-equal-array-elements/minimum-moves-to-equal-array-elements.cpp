class Solution {
public:
    int minMoves(vector<int>& nums) {
        long minVal = nums[0];
        long sum = 0;

    for(int i = 0;i<nums.size();i++){
        if(nums[i]<minVal){
            minVal = nums[i];
        }
        sum += nums[i];
    }
    return (int)(sum - (long)nums.size() * minVal);
    }
};