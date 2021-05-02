import sys;input=sys.stdin.readline
from collections import deque
n=int(input())
cap=[[0]*52 for _ in range(52)]
flow=[[0]*52 for _ in range(52)]
adj=[[]for _ in range(52)]
def conv(a):
	return ord(a)-71 if ord(a)>96 else ord(a)-65
for _ in range(n):
	a,b,c=input().split()
	a,b,c=conv(a),conv(b),int(c)
	cap[a][b]+=c
	cap[b][a]+=c
	adj[a].append(b)
	adj[b].append(a)

S=conv('A');E=conv('Z');ans=0
while 1:
	deq=deque([S])
	visit=[False]*52
	prev=[-1]*52
	m=1<<31
	while deq:
		cur=deq.popleft()
		if cur==E:
			break
		for i in adj[cur]:
			residual=cap[cur][i]-flow[cur][i]
			if not visit[i] and residual>0:
				visit[i]=1
				deq.append(i)
				prev[i]=cur
	if cur!=E: break
	path=[]
	while 1:
		path.append(cur)
		p=prev[cur]
		m=min(m,cap[p][cur]-flow[p][cur])
		cur=p
		if cur==S:
			path.append(S)
			break
	path=iter(path)
	forw=next(path)
	for i in path:
		flow[i][forw]+=m
		flow[forw][i]-=m
		forw=i
	ans+=m
print(ans)