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
            maze[i][j]=min(a[j],b[i])


for i in maze:
    print(*i)
