class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int target = 0;
        int maxCount = 0;
        for(int i = 0;i<nums.size();i++){
            int curr = nums[i];
            int count = 0;
            for(int j = 1;j<nums.size();j++){
                if(nums[j-1] == key && nums[j] == curr){
                    count++;
                }
            }

            if(maxCount < count){
                maxCount = count;
                target = curr;
            }
        }

        return target;
    }
};