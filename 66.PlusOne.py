# 66. Plus One
# Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
# The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
# You may assume the integer does not contain any leading zero, except the number 0 itself.
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if len(digits) == 0:
            return []
        increment = True
        for i in range(len(digits) - 1, -1, -1):
            now = digits[i] + 1
            if now > 9:
                digits[i] = 0
            else:
                digits[i] = now
                increment = False
                break
        if increment:
            digits.insert(0, 1)
        return digits


if __name__ == '__main__':
    s = Solution()
    print(s.plusOne([1,2,3,4]))
    print(s.plusOne([9]))
    print(s.plusOne([9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9]))
 