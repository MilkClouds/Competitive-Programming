from math import *

a = 1
for i in range(1,17):
	a = i*a//gcd(i, a)

A = []
n, m = map(int, input().split())
for i in range(n):
	A.append([*map(int, input().split())])

for i in range(n):
	for j in range(m):
		if i + j & 1:
			print(a + A[i][j] ** 4, end = ' ')
		else:
			print(a, end = ' ')
	print()