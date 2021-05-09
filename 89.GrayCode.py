# 89. Gray Code
# The gray code is a binary numeral system where two successive values differ in only one bit.
# Given an integer n representing the total number of bits in the code, return any sequence of gray code.
# A gray code sequence must begin with 0.
from typing import List


class Solution:
    """经过几次失败，发现了一个规律，实际上每进一位+1，只是需要把前面的所有值反向再走一遍即可，
    这样从0到1最高位变了再反向从1到0即可，所有值都能遍历到
    """

    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return []
        # result = [0]
        # for i in range(n):
        #     cur_bit = 1 << i
        #     cur_len = len(result)
        #     for j in range(cur_len - 1, -1, -1):
        #         result.append(cur_bit + result[j])
        # return result

        # 更优雅一点的实现
        result = [0, 1]
        i = cur_bit = 1
        while i < n:
            cur_bit <<= 1
            for j in result[::-1]:
                result.append(cur_bit | j)
            i += 1
        return result


if __name__ == '__main__':
    s = Solution()
    # print(s.grayCode(1))
    # print(s.grayCode(2))
    # print(s.grayCode(3))  # [0,1,3,2,6,7,5,4]
    # print(s.grayCode(4))
    print(s.grayCode(5))
    for i in range(16):
        print(i, len(s.grayCode(i)))
