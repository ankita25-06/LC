class Solution(object):
    def sortPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        k = -1
        for i in range (1,n):
            if nums[i] != i:
                if k == -1:
                    k = nums[i]
                else:
                    k &= nums[i]

        if k == -1:
            return 0
        
        return k