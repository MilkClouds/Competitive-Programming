import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    t = 1
    while n & 1 == 0:
        n >>= 1
        t <<= 1
    print(-1 if n == 1 else min(n, 2 * t))