import sys
input=sys.stdin.readline

INF=1<<30
v=int(input())
e=int(input())
g=[[INF]*v for _ in range(v)]

for _ in range(e):
	a,b,c=map(lambda x:int(x)-1,input().split())
	g[a][b]=min(g[a][b],c+1)

for m in range(v):
	for s in range(v):
		for e in range(v):
			g[s][e]=min(g[s][e],g[s][m]+g[m][e])
for i in range(v):
	g[i][i]=INF
for i in g:
	for j in i:
		print(j if j!=INF else 0,end=' ')
	print()
			