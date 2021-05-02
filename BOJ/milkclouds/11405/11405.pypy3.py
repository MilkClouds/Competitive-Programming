from collections import deque
import sys
input=sys.stdin.readline

N,M=map(int,input().split())

# 소스(S)->서점->인간->싱크(E)
S=N+M
E=N+M+1
total=N+M+2
INF=1<<40

adj=[[]for _ in range(total)]
dist=[[0]*total for _ in range(total)]
capacity=[[0]*total for _ in range(total)]
flow=[[0]*total for _ in range(total)]

left=list(range(M)) # 서점들
right=list(range(M,N+M)) # 인간들
adj[S]=left
adj[E]=right

for u in range(M):
    adj[u]=right+[S]
for u in range(M,N+M):
    adj[u]=left+[E]

for u,cap in enumerate(map(int,input().split())):
    u+=M
    capacity[u][E]=cap #인간->E

for u,cap in enumerate(map(int,input().split())):
    capacity[S][u]=cap #S->서점

for i in range(M):
    for j,d in enumerate(map(int,input().split())):
        j+=M
        dist[i][j]=d #서점->인간
        dist[j][i]=-d
        capacity[i][j]=INF

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
        minFlow=min(minFlow, capacity[u][v]-flow[u][v])
        v=u
    v=E
    while v != S:
        u=prev[u]
        ret+=dist[u][v]*minFlow
        flow[u][v]+=minFlow
        flow[v][u]-=minFlow
        v=u
    return ret

ans=0
while 1:
    prev=SPFA(S,E)
    if prev[E]==-1:break
    ans+=MCMF(S,E,prev)
print(ans)