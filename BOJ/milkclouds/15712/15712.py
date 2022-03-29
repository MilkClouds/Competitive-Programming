from math import gcd
a, r, n, m = map(int,input().split())
def solve(a, k):
    if k == 0:
        return a
    return solve(a, k - 1) * (1 + pow(r, 1 << k - 1, m)) % m
pre = 1
ans = 0
for i in range(50):
    if n & (1 << i):
        ans = (ans + solve(a * pre, i)) % m
        pre = pre * pow(r, 1 << i, m) % m
print(ans)