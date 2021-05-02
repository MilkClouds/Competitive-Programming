import sys
input=sys.stdin.readline

def dfs(u):
    if visit[u]:return False
    visit[u]=True
    for v in adj[u]:
        if rev[v]==-1 or dfs(rev[v]):
            save[u]=v
            rev[v]=u
            return True

for _ in range(int(input())):
    N,M=map(int,input().split())
    adj=[[]for _ in range(1000)]
    save=[-1]*1000;rev=[-1]*1000
    ans=0
    for i in range(M):
        a,b=map(int,input().split())
        adj[i]=list(range(a-1,b))
    for i in range(M):
        visit=[False]*1000
        if ~save[i] or dfs(i):
            ans+=1
    print(ans)