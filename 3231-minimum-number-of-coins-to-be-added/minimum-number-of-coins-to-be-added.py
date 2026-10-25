class Solution(object):
    def minimumAddedCoins(self, coins, target):
        """
        :type coins: List[int]
        :type target: int
        :rtype: int
        """
        coins.sort()
        added_coins = 0
        curr_max = (0)
        i = 0
        n = len(coins)

        while curr_max < target:
            if i < n and coins[i] <= curr_max+1:
                curr_max += coins[i]
                i += 1
            else:
                curr_max += curr_max+1
                added_coins += 1
        
        return added_coins