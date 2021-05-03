# 70. Climbing Stairs
# You are climbing a staircase. It takes n steps to reach the top.
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

# f(n) = f(n-1) + f(n-2)
# f(n-1) = f(n-2) + f(n-3)
# f(n-2) = f(n-3) + f(n-4)
# ···
# f(2) = f(1) + f(0)
# f(1) = f(0) + f(-1)
# f(0) = 1
# f(<0) = 0

class Solution:
    def climbStairs(self, n: int) -> int:
        step1, step2 = 0, 1
        for i in range(0, n):
            if i & 1 == 0:
                step1 = step1 + step2
            else:
                step2 = step1 + step2
        return step2 if n & 1 == 0 else step1
        # 递归不可取
        # return self.nextStep(0, n)

    def nextStep(self, cur: int, n: int) -> int:
        if cur == n:
            return 1
        elif cur > n:
            return 0
        else:
            return self.nextStep(cur + 1, n) + self.nextStep(cur + 2, n)


if __name__ == '__main__':
    s = Solution()
    print(s.climbStairs(2))
    print(s.climbStairs(3))
    print(s.climbStairs(20))
