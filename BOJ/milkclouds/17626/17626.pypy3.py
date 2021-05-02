from collections import deque

N = int(input())
dp = [5] * 50001
Q = deque()
for i in range(1, int(N ** .5) + 1):
	dp[i * i] = 1
	Q.append((i * i, 1))

for step in range(1, 4):
	while Q and Q[0][1] == step:
		u = Q.popleft()[0]
		for i in range(1, int((N - u) ** .5) + 1):
			v = u + i * i
			if dp[v] == 5:
				dp[v] = step + 1
				Q.append((v, step + 1))

print(dp[N])

