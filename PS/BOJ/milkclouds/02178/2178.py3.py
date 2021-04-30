from collections import deque
'''
n,m=10,10
r=''1101111110
0110111111
1110111111
1110111111
1110111111
1110111111
1110111111
1110111111
1110111111
1111101111
''
maze=[]
for i in r.split('\n'):
	maze.append(list(map(int,i)))

'''
n,m=map(int,input().split())
maze=[]
for _ in range(n):
	maze.append(list(map(int,input())))

act=[(-1,0),(0,-1),(0,1),(1,0)]

dist=[[1000000]*m for i in range(n)]
mdist=[[i+j+1 for j in range(m)] for i in range(n)]
def bfs():
	stack=deque([(0,0,1)])
	check=[[0]*m for i in range(n)]
	while stack :
		a,b,d=stack.popleft()
		#print(a,b,d)
		dist[a][b]=min(dist[a][b],d)
		if (a,b)==(n-1,m-1) and d==mdist[n-1][m-1]: break
		for dx,dy in act:
			x,y=a+dx,b+dy
			if 0<=x<n and 0<=y<m:
				if maze[x][y]:
					if dist[x][y]>d and check[x][y]==0:
						check[x][y]=1
						stack.append((x,y,d+1))
	print(dist[n-1][m-1])

bfs()