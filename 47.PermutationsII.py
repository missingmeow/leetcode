# 47. Permutations II
# Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        duplicate = []
        for i in range(len(nums)):
            if duplicate.count(nums[i]) != 0:
                continue
            nums[0], nums[i] = nums[i], nums[0]
            duplicate.append(nums[0])
            self.recursion(nums[0:1], nums[1:], result)
        return result

    def recursion(self, front: List[int], left: List[int], result: List[List[int]]):
        if len(left) <= 1:
            result.append(front + left)
            return
        duplicate = []
        for i in range(len(left)):
            if duplicate.count(left[i]) != 0:
                continue
            left[0], left[i] = left[i], left[0]
            duplicate.append(left[0])
            self.recursion(front + left[0:1], left[1:], result)


if __name__ == '__main__':
    s = Solution()
    print(s.permute([1]))
    print(s.permute([1, 1, 2]))
    print(s.permute([1, 2, 3]))
    print(len(s.permute([1, 2, 3, 4])))
    print(len(s.permute([1, 2, 3, 4, 5])))
    print(len(s.permute([1, 2, 3, 4, 5, 6, 6])))
