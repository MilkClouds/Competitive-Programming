import sys
input=sys.stdin.readline

act=[(i-1,j-1) for i in range(3) for j in range(3) if (i,j)!=(1,1)]

while 1:
	w,h=map(int,input().split())
	if (w,h)==(0,0): exit()
	graph=[list(map(int,input().split())) for i in range(h)]
	islands=0
	check=[[0]*w for i in range(h)]; checks=0
	while 1:
		stack=[]
		for i in range(h):
			if stack:break
			for j in range(w):
				if check[i][j]==0 and graph[i][j]: stack=[(i,j)];check[i][j]=1;checks+=1;break
		if not stack: break
		while stack:
			x,y=stack.pop()
			for a,b in act:
				i,j=x+a,y+b
				if 0<=i<h and 0<=j<w:
					if check[i][j]==0:
						if graph[i][j]:
							stack.append((i,j))
							check[i][j]=1
		islands+=1
	print(islands)