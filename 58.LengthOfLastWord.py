# 58. Length of Last Word
# Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
# A word is a maximal substring consisting of non-space characters only.

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ':
                if count == 0:
                    continue
                return count
            count += 1
        return count


if __name__ == '__main__':
    s = Solution()
    print(s.lengthOfLastWord('   '))
    print(s.lengthOfLastWord("Hello World"))
    print(s.lengthOfLastWord("Hello "))
    print(s.lengthOfLastWord("Hello World    "))
