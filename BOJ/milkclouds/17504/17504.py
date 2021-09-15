from fractions import *
f = Fraction
input()
ans = f(0)
for i in [*map(int, input().split())][::-1]:
    ans = f(1) / (i + ans) if ans else f(1) / i
ans = 1 - ans
print(ans.numerator, ans.denominator)