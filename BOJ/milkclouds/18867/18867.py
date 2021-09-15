from itertools import *
import sys

T = {}
for i in range(123):
	if chr(i).isalnum():
		T[pow(i, 814, 20200429)] = i

A = {}
for i in combinations(T, 4):
	A[sum(i)] = [T[j] for j in i]

for i in A:
	if A.get(20200402 - i):
		print(*map(chr, A[i] + A[20200402 - i]), sep = '')
		break
	