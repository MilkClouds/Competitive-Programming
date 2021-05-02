import sys
input=sys.stdin.readline
inp='''2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3
'''
inp=iter(inp.split('\n'))
#def input():
#	return next(inp)
n,m=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(n)]
pSum=[[0]*(1+m) for _ in range(1+n)]
for i in range(1,1+n):
	for j in range(1,1+m):
		pSum[i][j]=pSum[i][j-1]+pSum[i-1][j]-pSum[i-1][j-1]+a[i-1][j-1]

for _ in range(int(input())):
	i,j,x,y=map(int,input().split())
	i-=1;j-=1
	print(pSum[x][y]-pSum[x][j]-pSum[i][y]+pSum[i][j])
	