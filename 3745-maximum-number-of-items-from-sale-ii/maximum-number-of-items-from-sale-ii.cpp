class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        long long remBudget = budget;
        long long minPrice = LLONG_MAX;
        int maxFactor = 0;

        for(const auto& item : items){
            int f = item[0];
            long long p = item[1];
            minPrice = min(minPrice,p);
            maxFactor = max(maxFactor,f);
        }

        vector<long long>freq(maxFactor+1,0);
        for(const auto& item : items)freq[item[0]]++;

        for(int d = 1;d<= maxFactor;d++){
            if(freq[d] == 0)continue;
            for(int m = 2*d;m <=maxFactor;m += d){
                freq[d] += freq[m];
            }
        }

        map<long long, long long> boostByPrice;
        for (const auto& item : items) {
            int f = item[0];
            long long p = item[1];
            long long gain = freq[f] - 1;
            if (gain > 0 && p <= 2 * minPrice) {
                boostByPrice[p] += gain;
            }
        }

        long long totalItems = 0;
        for (const auto& [p, gain] : boostByPrice) {
            if (remBudget < p) break;
            long long take = min(gain, remBudget / p);
            totalItems += 2 * take;
            remBudget -= take * p;
        }

        totalItems += remBudget / minPrice;

        return static_cast<int>(totalItems);
    }
};