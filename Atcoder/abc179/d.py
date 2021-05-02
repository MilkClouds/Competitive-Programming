MI = lambda: map(int, input().split())
MOD = 998244353
N, K = MI()
dp = [0] * N
dpS = [0] * (N + 1)
dp[0] = 1
dpS[1] = 1
A = []
for i in range(K):
    L, R = MI()
    A.append((L, R))

def get(i):
    if i < 0: i == 0
    return dpS[i]

for i in range(1, N):
    for j in range(K):
        dp[i] += get(i - A[j][0] + 1) - get(i - A[j][1])
        dp[i] %= MOD
    dpS[i + 1] = dpS[i] + dp[i]

print(dp[N - 1])
