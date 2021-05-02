from math import *
def Comb(n, r):
	return factorial(n) // factorial(r) // factorial(n - r)

R, C, W = map(int, input().split())
R -= 1
C -= 1
ans = 0
for i in range(W):
	for j in range(i + 1):
		ans += Comb(R + i, C + j)
print(ans)