import sys
input=sys.stdin.readline

n,m,h=map(int,input().split())
maze=[[0]*m for _ in range(n)]
a=list(map(int,input().split()))
b=list(map(int,input().split()))
Q=[]
for i in range(n):
    for j,v in enumerate(map(int,input().split())):
        if v==1:
            Q.append((i,j))

chka=[False]*101
chkb=[False]*101
def solve(cur):
    if cur==len(Q):
        return 1
    i,j=Q[cur]
    maze[i][j]=min(a[j],b[i])
    solve(cur+1)
solve(0)
for i in maze:
    print(*i)
