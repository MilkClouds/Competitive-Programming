from math import *
gcd = lambda x, y: gcd(y, x % y) if x % y else y
lcm = lambda x, y: x * y // gcd(x, y)
ret = 0
N = int(input())
f = lambda i: int('1' * i)
V = (f(2), f(3), f(5), f(7), f(11), f(13), f(17))
M = sum(i <= N for i in V)
for i in range(1, 1 << M):
    d = 1; c = 0
    for j in range(M):
        if i & (1 << j):
            d = lcm(d, V[j])
            c += 1
    ret += (1 if c % 2 else -1) * (N // d)
print(ret)