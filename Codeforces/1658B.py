import sys
input = sys.stdin.readline
MOD = 998244353
fact = lambda i: fact(i - 1) * i % MOD if i else 1
for _ in range(int(input())):
    n = int(input())
    print(0 if n % 2 else fact(n // 2) ** 2 % MOD)