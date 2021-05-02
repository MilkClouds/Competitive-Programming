import sys;input=sys.stdin.readline
from collections import deque

n,T=map(int,input().split())
vertex=[(0,0)]
visit=[False]*(n+1)
for i in range(n):
    x,y=map(int,input().split())
    vertex.append((x,y))

vertex.sort()

deq=deque([0])
visit[0]=1

while deq:
    u=deq.popleft()
    if vertex[u][1]==T:
        print(visit[u]-1)
        exit()
    for i in range(u+1,n+1):
        if vertex[i][0]-vertex[u][0]>2:break
        if abs(vertex[i][1]-vertex[u][1])>2 or visit[i]:continue
        visit[i]=visit[u]+1
        deq.append(i)
    for i in range(u-1,0,-1):
        if vertex[u][0]-vertex[i][0]>2:break
        if abs(vertex[i][1]-vertex[u][1])>2 or visit[i]:continue
        visit[i]=visit[u]+1
        deq.append(i)
print(-1)