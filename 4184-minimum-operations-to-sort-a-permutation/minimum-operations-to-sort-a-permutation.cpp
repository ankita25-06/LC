class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)return 0;

        int dropCount = 0;
        int incCount = 0;
        int zeroIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroIndex = i;
            }
            
            if (nums[i] > nums[(i + 1) % n]) {
                dropCount++;
            }
            if (nums[i] < nums[(i + 1) % n]) {
                incCount++;
            }
        }

        int ans = INT_MAX;

         if (dropCount <= 1) {
            ans = min(ans, zeroIndex);
            
            if (zeroIndex > 0) {
                ans = min(ans, n - zeroIndex + 2);
            }
        }
        
        if (incCount <= 1) {
            ans = min(ans, zeroIndex + 2);
            ans = min(ans, n - zeroIndex);
        }
        
        if (ans == INT_MAX) {
            return -1;
        }
        
        return ans;
    }
};