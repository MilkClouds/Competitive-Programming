import sys;input=sys.stdin.readline
sys.setrecursionlimit(999999)
m,n=map(int,input().split())

world=[list(map(int,input().split())) for _ in range(m)]
dp=[[-1]*n for i in range(m)]
dx=[0,0,-1,1]
dy=[1,-1,0,0]
def visit(x,y):
	if (x==m-1 and y==n-1): return 1
	if ~dp[x][y]:return dp[x][y]
	dp[x][y]=0
	for i in range(4):
		nx=x+dx[i]
		ny=y+dy[i]
		if not (0<=nx<m and 0<=ny<n): continue
		if world[x][y]>world[nx][ny]:
			dp[x][y]+=visit(nx,ny)
	return dp[x][y]

visit(0,0)
print(dp[0][0])