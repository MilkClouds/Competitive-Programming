N,M=map(int,input().split())
A=[list(map(int,input()))for i in range(N)]
ans=0
def flip(x,y):
	global ans
	ans+=1
	for i in range(3):
		for j in range(3):
			A[i+x][j+y]^=1
for i in range(N):
	for j,x in enumerate(map(int,input())):
		A[i][j]^=x
		if i<N-2 and j<M-2:
			A[i][j] and flip(i,j)
for i in range(N):
	if 1 in A[i]:
		print(-1)
		exit()
print(ans)