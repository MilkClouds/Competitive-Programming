import sys
from bisect import *
input = sys.stdin.readline
MI = lambda: map(int, input().split())

N, K = MI()
A = []
for i in range(N):
	a, b = MI()
	A.append((a, b))
A.sort()

for i in range(N):
	if K < A[i][0]:
		break
	K += A[i][1]

print(K)