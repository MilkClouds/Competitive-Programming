import sys
input=sys.stdin.readline
sys.setrecursionlimit(109999)

def scc(u):
	global cnt,sccC
	cnt+=1
	dfsn[u]=ret=cnt
	st.append(u)
	for v in adj[u]:
		if dfsn[v]==0:
			ret=min(ret,scc(v))
		elif sccn[v]==-1:
			ret=min(ret,dfsn[v])
	if ret==dfsn[u]:
		while st:
			p=st.pop()
			sccn[p]=sccC
			if p==u: break
		sccC+=1
	return ret

for _ in range(int(input())):
	N,M=map(int,input().split())
	adj=[[]for _ in range(N+1)]
	dfsn=[0]*(N+1)
	sccn=[-1]*(N+1)
	st=[]
	sccC=cnt=0
	for _ in range(M):
		a,b=map(int,input().split())
		adj[a].append(b)
	for u in range(1,N+1):
		dfsn[u] or scc(u)
	degree=[0]*sccC
	for u in range(1,1+N):
		for v in adj[u]:
			if sccn[u]!=sccn[v]:
				degree[sccn[v]]+=1
	ans=0
	for i in range(sccC):
		if degree[i]==0:
			ans+=1
	print(ans)