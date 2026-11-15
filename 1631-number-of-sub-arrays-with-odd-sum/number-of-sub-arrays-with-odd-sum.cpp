class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd_count = 0;
        long long even_count = 1;
        
        long long current_prefix_sum = 0;
        long long total_odd_subarrays = 0;
        int MOD = 1e9 + 7;
        
        for (int num : arr) {
            current_prefix_sum += num;
            
            if (current_prefix_sum % 2 != 0) {
                total_odd_subarrays += even_count;
                odd_count++;
            } else {
                total_odd_subarrays += odd_count;
                even_count++;
            }
        }
        
        return total_odd_subarrays % MOD;
    }
};