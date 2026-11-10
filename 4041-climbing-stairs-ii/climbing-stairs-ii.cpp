class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1,INT_MAX);

        dp[0]= 0;

        for(int j = 1;j<=n;j++){
            for(int i = 1;i<=3;i++){
                if (j - i >= 0) {
                    long long jump_cost = costs[j - 1] + (i * i);
                    dp[j] = min(dp[j], dp[j - i] + jump_cost);
                }
            }
        }
        return dp[n];
    }
};