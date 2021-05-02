import sys
input=sys.stdin.readline
N,M=map(int,input().split())
pSum=[[0]*(N+1) for _ in range(N+1)]
def update(x,y,v):
	while(x<=N):
		j=y;
		while(j<=N):
			pSum[x][j]+=v
			j+=j&-j
		x+=x&-x
def fsum(x,y):
	ret=0
	while(x):
		j=y
		while(j):
			ret+=pSum[x][j]
			j&=j-1
		x&=x-1
	return ret
for i in range(N):
	for j,v in enumerate(map(int,input().split())):
		update(i+1,j+1,v)
for _ in range(M):
	t=map(int,input().split())
	if(next(t)):
		x1,y1,x2,y2=t
		print(fsum(x2,y2)+fsum(x1-1,y1-1)-fsum(x2,y1-1)-fsum(x1-1,y2))
	else:
		x,y,c=t
		update(x,y,c-(fsum(x,y)+fsum(x-1,y-1)-fsum(x-1,y)-fsum(x,y-1)))