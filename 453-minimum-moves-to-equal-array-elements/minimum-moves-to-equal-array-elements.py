class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_val = min(nums)
        total_sum = sum(nums)
        n = len(nums)
        return total_sum - min_val * n
