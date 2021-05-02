import sys; input=sys.stdin.readline

sys.setrecursionlimit(100000)

N,M = map(int,input().split())
adj=[[] for _ in range(N)]
visit=[0]*N

for _ in range(M):
    u,v = map(int,input().split())
    u-=1; v-=1;
    adj[u].append(v)
    adj[v].append(u)

def DFS(u):
    if visit[u]: return 0
    visit[u]=1
    for v in adj[u]:
        DFS(v)
    return 1

cnt = 0

for u in range(N):
    cnt += DFS(u)

print( cnt )