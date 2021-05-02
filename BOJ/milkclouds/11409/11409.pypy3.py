from collections import deque
import sys
input=sys.stdin.readline

N,M=map(int,input().split())

# 소스(S)->직원->일->싱크(E)
S=N+M
E=N+M+1
total=N+M+2
INF=1<<40

adj=[[]for _ in range(total)]
dist=[[0]*total for _ in range(total)]
capacity=[[0]*total for _ in range(total)]
flow=[[0]*total for _ in range(total)]

left=list(range(N))
right=list(range(N,N+M))
adj[S]=left
adj[E]=right

adj[:N]=[[S]for _ in range(N)]
adj[N:N+M]=[[E]for _ in range(M)]

capacity[S][:N]=[1]*N
for i in capacity[N:N+M]:
    i[E]=1

for u in range(N):
    t=map(int,input().split())
    for _ in range(next(t)):
        v=next(t);d=next(t)
        v+=N-1
        capacity[u][v]=1
        dist[u][v]=-d
        dist[v][u]=d
        adj[u].append(v)
        adj[v].append(u)

def SPFA(S,E):
    d=[INF]*total
    d[S]=0
    Q=deque([S])
    inQueue=[False]*total
    prev=[-1]*total
    while Q:
        u=Q.popleft()
        inQueue[u]=False
        for v in adj[u]:
            if capacity[u][v]-flow[u][v]>0 and d[u]+dist[u][v]<d[v]:
                d[v]=d[u]+dist[u][v]
                prev[v]=u
                if not inQueue[v]:
                    Q.append(v)
                    inQueue[v]=True
    return prev

def MCMF(S,E,prev):
    ret=0
    minFlow=INF
    v=E
    while v != S:
        u=prev[v]
        ret+=-dist[u][v]
        flow[u][v]+=1
        flow[v][u]-=1
        v=u
    return ret

ans=idx=0
while 1:
    prev=SPFA(S,E)
    if prev[E]==-1:break
    idx+=1
    ans+=MCMF(S,E,prev)
print(idx)
print(ans)