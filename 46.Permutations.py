# 46. Permutations
# Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        for i in range(len(nums)):
            nums[0], nums[i] = nums[i], nums[0]
            self.recursion(nums[0:1], nums[1:], result)
        return result

    def recursion(self, front: List[int], left: List[int], result: List[List[int]]):
        if len(left) <= 1:
            result.append(front + left)
            return
        for i in range(len(left)):
            left[0], left[i] = left[i], left[0]
            self.recursion(front + left[0:1], left[1:], result)


if __name__ == '__main__':
    s = Solution()
    print(s.permute([1]))
    print(s.permute([0, 1]))
    print(s.permute([1, 2, 3]))
    print(len(s.permute([1, 2, 3, 4])))
    print(len(s.permute([1, 2, 3, 4, 5])))
    print(len(s.permute([1, 2, 3, 4, 5, 6])))
