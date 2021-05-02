K = 3
X = [*map(int, input().split())]
C = [0] * K
ans = 0
for i in range(K):
	ans += X[i] // K
	C[X[i] % K] += 1
m = K
for i in range(K):
	K -= C[i]
	m = min(m, i + K)
print(ans + m)
