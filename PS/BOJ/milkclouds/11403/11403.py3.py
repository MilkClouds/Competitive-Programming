import sys
input=sys.stdin.readline

n=int(input())
INF=1<<31
g=[[INF]*n for i in range(n)]
for i in range(n):
	for j,v in enumerate(map(int,input().split())):
		if not v:continue
		g[i][j]=1

for m in range(n):
	for s in range(n):
		for e in range(n):
			g[s][e]=min(g[s][e],g[s][m]+g[m][e])

for i in range(n):
	for j in range(n):
		print(1 if g[i][j]!=INF else 0,end=" ")
	print()