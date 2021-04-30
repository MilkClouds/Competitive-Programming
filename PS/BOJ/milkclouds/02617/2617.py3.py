N,M=map(int,input().split())
adj=[[]for _ in range(N+1)]
class Edge:
	def __init__(self,u,v):
		self.V=[u,v]
for _ in range(M):
	u,v=map(int,input().split())
	e=Edge(u,v)
	adj[u].append(e)
	adj[v].append(e)

def dfs(u,dir=1):
	visit[u]=1
	ret=0
	for e in adj[u]:
		v=e.V[dir]
		if v==u or visit[v]: continue
		ret+=dfs(e.V[dir],dir)
	return ret+1

T=(N+1)//2
ret=0
for i in range(1,N+1):
	visit=[0]*(N+1)
	if dfs(i)>T or dfs(i,0)>T:
		ret+=1
print(ret)