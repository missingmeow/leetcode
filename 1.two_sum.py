# 1. Two Sum
# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            new_tar = target - nums[i]
            for j in range(i + 1, len(nums)):
                if (nums[j] == new_tar):
                    return [i, j]
        return []


if __name__ == '__main__':
    s = Solution()
    print(s.twoSum([1, 2, 3, 4], 6))
