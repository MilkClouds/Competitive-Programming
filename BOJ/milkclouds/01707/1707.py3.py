import sys
input=sys.stdin.readline
sys.setrecursionlimit(400000)

def dfs(u,color):
    global f
    if f:return
    c[u]=color
    for v in adj[u]:
        if c[v]:
            if c[v]==color:
                f=1
                return
            continue
        dfs(v,-color)

for _ in range(int(input())):
    V,E=map(int,input().split())
    adj=[[]for _ in range(V+1)]
    c=[0]*(V+1);f=0
    for _ in range(E):
        a,b=map(int,input().split())
        adj[a].append(b)
        adj[b].append(a)
    for u in range(1,1+V):
        c[u] or dfs(u,1)
        if f:break
    print("NO" if f else 'YES')