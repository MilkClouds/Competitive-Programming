import sys
input=sys.stdin.readline

n,m=map(int,input().split())
INF=(1<<31)-1
g=[[INF]*n for _ in range(n)]
for _ in range(m):
	a,b=map(int,input().split())
	a-=1;b-=1
	g[a][b]=1

for mm in range(n):
	for s in range(n):
		for e in range(n):
			g[s][e]=min(g[s][mm]+g[mm][e],g[s][e])

ret=0
for i in range(n):
	no=0
	for j in range(n):
		if g[j][i]!=INF or g[i][j]!=INF:
			no+=1
	if n-1== no:ret+=1
print(ret)