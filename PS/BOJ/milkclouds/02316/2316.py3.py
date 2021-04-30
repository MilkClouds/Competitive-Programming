import sys
input=sys.stdin.readline
INF=1<<50

def SPFA(V):
    d=[INF]*V;prev=[-1]*V;inQueue=[False]*V
    d[Source]=0
    Q=[Source]
    while Q:
        u=Q.pop()
        if u==Sink:
            return prev
        inQueue[u]=False
        for v in adj[u]:
            if capacity[u][v]-flow[u][v]>0 and d[u]<d[v]:
                d[v]=d[u]
                prev[v]=u
                inQueue[v] or Q.append(v)
    return prev

def MCMF(prev):
    v=Sink
    while v!=Source:
        u=prev[v]
        flow[u][v]+=1
        flow[v][u]-=1
        v=u
    return

if 1:
    V,E=map(int,input().split())
    Source=0;Sink=1*2
    capacity=[[0]*V*2 for _ in range(V*2)]
    flow=[[0]*V*2 for _ in range(V*2)]
    adj=[[]for i in range(V*2)]
    for i in range(V):
        u=i*2;v=u+1
        capacity[u][v]=1
        adj[u].append(v)
        adj[v].append(u)
    capacity[Source][Source+1]=INF
    capacity[Sink][Sink+1]=INF
    for _ in range(E):
        u,v=map(int,input().split())
        u-=1;v-=1
        a,b=u,v
        if 1:
            u,v=2*u+1,2*v
            capacity[u][v]=1
            adj[u].append(v)
            adj[v].append(u)
        if 2:
            u,v=a,b
            u,v=2*u,2*v+1
            capacity[v][u]=1
            adj[u].append(v)
            adj[v].append(u)
    ans=0
    while 1:
        prev=SPFA(V*2)
        if prev[Sink]==-1:break
        ans+=1
        MCMF(prev)
    print(ans)