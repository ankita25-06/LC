class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMin(n,0);

        suffixMin[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suffixMin[i] = min(nums[i],suffixMin[i+1]);
        }

        int prefixMax= nums[0];
        int sum = 0;

        for(int i = 1;i<= n-2;i++){
            if(prefixMax < nums[i] && nums[i] < suffixMin[i+1]){
                sum += 2;
            }else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                sum += 1;
            }

            if (nums[i] > prefixMax) {
                prefixMax = nums[i];
            }
        }
        return sum;
    }
};