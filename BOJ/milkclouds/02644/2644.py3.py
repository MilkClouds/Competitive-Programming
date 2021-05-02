INF=100000

N=int(input())
a,b=map(int,input().split())

adj=[[] for _ in range(N+1)]

for _ in range(int(input())):
	x,y=map(int,input().split())
	adj[x].append(y)
	adj[y].append(x)

def dfs(u,par):
	global b,INF
	if u==b: return 0
	ret=INF
	for v in adj[u]:
		if v^par:
			ret=min(ret,dfs(v,u))
	return ret+1

t=dfs(a,0)
print(t if t<INF else -1)