class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        vector<int> bonus(n,0);

        for(int i = 0;i<n;i++){
            int factor_i = items[i][0];
            int count = 1;
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % factor_i == 0) {
                    count++;
                }
            }
            bonus[i] = count;
        }
        vector<int> dp(budget+1,0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            for (int w = budget; w >= price; w--) {
                dp[w] = max(dp[w], dp[w - price] + bonus[i]);
            }
        }
        for (int w = 0; w <= budget; w++) {
            for (int i = 0; i < n; i++) {
                int price = items[i][1];
                if (w >= price) {
                    dp[w] = max(dp[w], dp[w - price] + 1);
                }
            }
        }
        return dp[budget];
    }
};