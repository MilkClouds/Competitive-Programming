import sys
from bisect import *
input = sys.stdin.readline
MI = lambda: map(int, input().split())

N, M = MI()
A = []
for i in range(M):
	A.append([*MI()])
A.sort()
MAP = {N: 1}
i = 0
while i < M:
	MAP2 = {}
	while i < M - 1 and A[i][0] == A[i + 1][0]:
		MAP2[A[i][1]] = (MAP.get(A[i][1] - 1, 0) + MAP.get(A[i][1] + 1, 0)) > 0
		i += 1
	MAP2[A[i][1]] = (MAP.get(A[i][1] - 1, 0) + MAP.get(A[i][1] + 1, 0)) > 0
	for j in MAP2:
		MAP[j] = MAP2[j]
	i += 1
ans = 0
for i in MAP:
	ans += MAP[i] > 0
print(ans)