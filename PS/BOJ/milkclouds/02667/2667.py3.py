import sys
input=sys.stdin.readline
n=int(input())
maze=[list(map(int,input().rstrip()))for _ in range(n)]
visit=[[False]*n for _ in range(n)]
dx=[0,0,-1,1]
dy=[1,-1,0,0]
def dfs(x,y):
    if visit[x][y] or not maze[x][y]:return 0
    ret=0
    visit[x][y]=True
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<n:
            ret+=dfs(nx,ny)
    return ret+1
ans=[]
for i in range(n):
    for j in range(n):
        t=dfs(i,j)
        if t:
            ans.append(t)
print(len(ans))
print(*sorted(ans),sep='\n')