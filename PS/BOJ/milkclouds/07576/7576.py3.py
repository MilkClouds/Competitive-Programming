from collections import deque

m,n=map(int,input().split())

q=deque()
maze=[]
for i in range(n):
	t=list(map(int,input().split()))
	for j in range(m):
		if t[j]==1: q.append((i,j))
	maze.append(t)

act=((1,0),(-1,0),(0,1),(0,-1))
index=0
while 1:
	for i in range(len(q)):
		a,b=q.popleft()
		for dx,dy in act:
			x,y=a+dx,b+dy
			if 0<=x<n and 0<=y<m:
				if maze[x][y]==0:
					q.append((x,y))
					maze[x][y]=1
	if not q: break
	index+=1

no=0
for i in maze:
	if 0 in i: no=1;break
print(-1 if no else index)