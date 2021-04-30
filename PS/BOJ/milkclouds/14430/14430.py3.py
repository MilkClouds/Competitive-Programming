N,M=map(int,input().split())
dp=[[0]*M for _ in range(N)]
for i in range(N):
	for j,ore in enumerate(map(int,input().split())):
		dp[i][j]=max(dp[i][j-1],dp[i-1][j])+ore
print(dp[N-1][M-1])
