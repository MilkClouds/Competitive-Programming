import sys
input=sys.stdin.readline
INF=1<<50

def SPFA(V):
    d=[INF]*V;prev=[-1]*V;inQueue=[False]*V
    d[Source]=0
    Q=[Source]
    while Q:
        u=Q.pop()
        inQueue[u]=False
        for v in adj[u]:
            if capacity[u][v]-flow[u][v]>0 and d[u]+adj[u][v]<d[v]:
                d[v]=d[u]+adj[u][v]
                prev[v]=u
                inQueue[v] or Q.append(v)
    return prev

def MCMF(prev):
    ans=0;v=Sink
    while v!=Source:
        u=prev[v]
        ans+=adj[u][v]
        flow[u][v]+=1
        flow[v][u]-=1
        v=u
    return ans

for line in sys.stdin:
    V,E=map(int,line.split())
    Source=0;Sink=2*(V-1)
    capacity=[[0]*V*2 for _ in range(V*2)]
    flow=[[0]*V*2 for _ in range(V*2)]
    adj=[{} for _ in range(V*2)]
    for i in range(1,V-1):
        u=i*2;v=u+1
        adj[u][v]=0
        adj[v][u]=0
        capacity[u][v]=1
    for _ in range(E):
        u,v,c=map(int,input().split())
        u-=1;v-=1
        if u==V-1:
            u=Sink
        elif u:
            u=2*u+1
        if v==V-1:
            v=Sink
        elif v:
            v=2*v
        adj[u][v]=c
        adj[v][u]=-c
        capacity[u][v]=1
    ans=0
    prev=SPFA(V*2)
    ans+=MCMF(prev)
    prev=SPFA(V*2)
    ans+=MCMF(prev)
    print(ans)