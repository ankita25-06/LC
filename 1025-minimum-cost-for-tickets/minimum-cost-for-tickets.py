class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        travel_days = set(days)
        max_day = days[-1]

        dp = [0]*(max_day+1)

        for i in range (1,max_day+1):
            if i not in travel_days:
                dp[i] = dp[i-1]
            else:
                cost1 = dp[max(0, i - 1)] + costs[0]
                cost7 = dp[max(0, i - 7)] + costs[1]
                cost30 = dp[max(0, i - 30)] + costs[2]
                dp[i] = min(cost1, cost7, cost30)

        return dp[max_day]