n=int(input())
m=int(input())
INF=1<<20
#11:28
g=[[INF]*n for i in range(n)]
for i in range(m):
	a,b=map(lambda x:int(x)-1,input().split())
	g[a][b]=1

for m in range(n):
	for s in range(n):
		for e in range(n):
			g[s][e]=min(g[s][e],g[s][m]+g[m][e])
ret=[n-1]*n
for s in range(n):
	for e in range(n):
		if s==e: continue
		if g[s][e]!=INF:
			ret[s]-=1
		elif g[e][s]!=INF:
			ret[s]-=1
print(*ret,sep='\n')