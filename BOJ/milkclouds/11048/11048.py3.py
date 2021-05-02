import sys
input=sys.stdin.readline

N,M=map(int,input().split())

maze=[list(map(int,input().split())) for _ in range(N)]

memo=[[0]*M for _ in range(N)]

for i in range(N):
	for j in range(M):
		memo[i][j]=max(memo[i-1][j],memo[i][j-1])+maze[i][j]

print(memo[N-1][M-1])