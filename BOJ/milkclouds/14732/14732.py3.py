maze=[[0]*501 for i in range(501)];area=0
for _ in range(int(input())):
	a,b,c,d=map(int,input().split())
	for i in range(a,c):
		for j in range(b,d):
			if maze[i][j]==0:
				area+=1
				maze[i][j]=1
print(area)