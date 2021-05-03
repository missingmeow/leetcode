# 53. Maximum Subarray
# Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        maxi = nums[0]
        last = nums[0]
        for i in range(1, len(nums)):
            last += nums[i]
            if nums[i] > last:
                last = nums[i]
            if last > maxi:
                maxi = last
        return maxi


if __name__ == '__main__':
    s = Solution()
    arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(s.maxSubArray([-2, 1]))
    # arr = [5,4,-1,7,8]
    print(s.maxSubArray([-2, -1]))
    print(s.maxSubArray([-1, 1, 2, 1]))
    print(s.maxSubArray([-2, 3, 1, 3]))
