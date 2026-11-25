class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
         vector<int> nums;
         nums.reserve(n);
        
        for(int num1 : nums1){
            nums.push_back(num1);
        }
        for(int num2 : nums2){
            nums.push_back(num2);
        }

        sort(nums.begin(),nums.end());

        double median = 0;
        if(n%2 == 0){
            int a = n/2-1;
            int b = n/2;
            median = (nums[a]+nums[b])/2.0;
        }else{
            median = nums[n/2];
        }
        return median;
    }
};