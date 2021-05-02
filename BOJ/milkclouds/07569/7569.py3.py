from collections import deque

m,n,h=map(int,input().split())

q=deque()
maze=[]
for k in range(h):
	maz=[]
	for i in range(n):
		t=list(map(int,input().split()))
		for j in range(m):
			if t[j]==1: q.append((i,j,k))
		maz.append(t)
	maze.append(maz)

act=((1,0,0),(-1,0,0),(0,1,0),(0,-1,0),(0,0,1),(0,0,-1))
index=0
while 1:
	for i in range(len(q)):
		a,b,c=q.popleft()
		for dx,dy,dz in act:
			x,y,z=a+dx,b+dy,c+dz
			if 0<=x<n and 0<=y<m and 0<=z<h:
				if maze[z][x][y]==0:
					q.append((x,y,z))
					maze[z][x][y]=1
	if not q: break
	index+=1

no=0
for i in maze:
	for e in i:
		if 0 in e: no=1;break
print(-1 if no else index)