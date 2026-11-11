long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long totalcost = 0;
    long long shared = MIN(need1,need2);

    totalcost += shared*MIN((long long)costBoth,(long long)cost1+cost2);

    long long rem1 = need1 - shared;
        long long rem2 = need2 - shared;

        if (rem1 > 0) {
            totalcost += rem1*MIN(cost1, costBoth);
        }
         if (rem2 > 0) {
            totalcost += rem2*MIN(cost2, costBoth);
        }

        return totalcost;
}