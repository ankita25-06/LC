class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int length = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if (nums[i] != -1) {
                int count = 0;
                int curr = i;

                while (nums[curr] != -1) {
                    int next = nums[curr];
                    nums[curr] = -1;
                    curr = next;
                    count++;
                }

                length = max(length, count);
            }
        }

        return length;
    }
};