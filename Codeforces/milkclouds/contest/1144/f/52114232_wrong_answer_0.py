import sys;input=lambda:sys.stdin.readline().rstrip()
n,m=map(int,input().split())
adj=[[]for _ in range(200002)]
for _ in range(m):
    u,v=map(int,input().split())
    adj[u].append(v)

cnt=flag=0
visit=[False]*200005
def dfs(u,rec):
    global flag,cnt
    if visit[u]:return
    if rec>2:
        flag=1
        return
    visit[u]=1;cnt+=1
    for v in adj[u]:
        dfs(v,rec+1)

for i in range(1,n+1):
    flag or dfs(i,0)

print("NO" if flag else "YES\n"+"0"*m)