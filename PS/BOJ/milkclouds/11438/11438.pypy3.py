import sys;input=sys.stdin.readline
from collections import deque
sys.setrecursionlimit(299999)

N=int(input())
parent=[[0]*17 for _ in range(N+1)]
depth=[0]*(N+1)
adj=[set()for _ in range(N+1)]
for _ in range(N-1):
    a,b=map(int,input().split())
    adj[a].add(b)
    adj[b].add(a)

def dfs(u=1):
    for v in adj[u]:
        if depth[v]:continue
        parent[v][0]=u
        depth[v]=depth[u]+1
        dfs(v)
def bfs(u=1):
    Q=deque([1])
    while Q:
        u=Q.popleft()
        for v in adj[u]:
            if depth[v]:continue
            depth[v]=depth[u]+1
            parent[v][0]=u
            Q.append(v)
depth[1]=1
bfs()

for j in range(16):
    for i in range(1,N+1):
        parent[i][j+1]=parent[parent[i][j]][j]

M=int(input())
for _ in range(M):
    a,b=map(int,input().split())
    if depth[a]<depth[b]:a,b=b,a
    if depth[a]!=depth[b]:
        diff=depth[a]-depth[b]
        j=0
        while diff:
            if diff&1: a=parent[a][j]
            diff>>=1
            j+=1
    if a!=b:
        for j in range(16,-1,-1):
            if parent[a][j] and parent[b][j]!=parent[a][j]:
                a=parent[a][j]
                b=parent[b][j]
        a=parent[a][0]
    sys.stdout.write('%d\n'%a)