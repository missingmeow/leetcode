# 45. Jump Game II
# Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
# Each element in the array represents your maximum jump length at that position.
# Your goal is to reach the last index in the minimum number of jumps.
# You can assume that you can always reach the last index.
from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        # 比较简单，用一个列表，从左到右把到每一步的最小步骤记录下来，最后得到的就是最小的
        max_step = len(nums) - 1
        steps = [max_step] * len(nums)
        steps[0] = 0
        for i in range(len(nums)):
            for j in range(1, nums[i] + 1):
                next_index = i + j
                if next_index > max_step:
                    break
                if steps[next_index] > steps[i] + 1:
                    steps[next_index] = steps[i] + 1
        return steps[max_step]

        # 递归，慢
        # steps = [len(nums) - 1]
        # self.recursion(0, len(nums) - 1, nums, 0, steps)
        # return steps[0]

    def recursion(self, cur: int, all: int, nums: List[int], cur_step: int, min_step: List[int]) -> None:
        cur_step += 1
        for i in range(1, nums[cur] + 1):
            next_step = cur + i
            if next_step == all:
                if min_step[0] > cur_step:
                    min_step[0] = cur_step
                continue
            if next_step > all or nums[next_step] == 0 or cur_step >= min_step[0]:
                continue
            self.recursion(next_step, all, nums, cur_step, min_step)


if __name__ == '__main__':
    s = Solution()
    print(s.jump([2, 3, 1, 1, 4]))
    print(s.jump([2]))
    print(s.jump([2, 3, 0, 1, 4]))
    print(s.jump([8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6, 5, 1, 7, 0, 3, 4, 8, 3, 5,
                  9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7, 4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5]))
