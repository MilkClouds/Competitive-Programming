from math import *
import sys;input=sys.stdin.readline
N = int(input())

A = [int(input()) for _ in range(N)]

iv = A[1] - A[0]
for i in range(1, N-1):
    iv = gcd(iv, A[i + 1] - A[i])

ans = 0
for i in range(N-1):
    ans += (A[i + 1] - A[i]) // iv - 1
print(ans)