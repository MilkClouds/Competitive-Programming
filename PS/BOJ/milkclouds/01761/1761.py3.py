import sys
input=sys.stdin.readline
sys.setrecursionlimit(99999)

N=int(input())
dist=[{}for _ in range(N+1)];root_dist=[0]*(N+1)
for _ in range(N-1):
    u,v,d=map(int,input().split())
    dist[u][v]=dist[v][u]=d
depth=[0]*(N+1)
parent=[[0]*20 for _ in range(N+1)]
def dfs(u):
    for v in dist[u]:
        if depth[v]==0:
            parent[v][0]=u
            depth[v]=depth[u]+1
            root_dist[v]=root_dist[u]+dist[u][v]
            dfs(v)
depth[1]=1
dfs(1)

for j in range(20):
    for i in range(1,1+N):
        u=parent[i][j]
        if not u:continue
        v=parent[u][j]
        parent[i][j+1]=v

M=int(input())
for _ in range(M):
    u,v=map(int,input().split())
    x,y=u,v
    if depth[u]<depth[v]:u,v=v,u
    diff=depth[u]-depth[v]
    for j in range(20):
        if diff&1:
            u=parent[u][j]
        diff>>=1
    if u != v:
        for j in range(19,-1,-1):
            if parent[v][j] and parent[u][j]!=parent[v][j]:
                u=parent[u][j]
                v=parent[v][j]
        u=parent[u][0]
    print(root_dist[x]+root_dist[y]-2*root_dist[u])