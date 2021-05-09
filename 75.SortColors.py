# 75. Sort Colors
# Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
# We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j = 0, len(nums) - 1
        m = 0
        while i < j and m <= j:
            while nums[i] == 0 and i < j:
                i += 1
            while nums[j] == 2 and i < j:
                j -= 1
            if m < i:
                m = i
            while m <= j:
                if nums[m] == 0:
                    nums[i], nums[m] = nums[m], nums[i]
                    i += 1
                    break
                if nums[m] == 2:
                    nums[j], nums[m] = nums[m], nums[j]
                    j -= 1
                    break
                m += 1


if __name__ == '__main__':
    s = Solution()
    nums = [2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0]
    s.sortColors(nums)
    print(nums)
