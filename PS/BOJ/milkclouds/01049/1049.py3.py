import sys
input=sys.stdin.readline
n,m=map(int,input().split())
pr={}
minsin=1000
minpac=1000
for _ in range(m):
	a,b=map(int,input().split())
	minpac=min(minpac,a)
	minsin=min(minsin,b)

priority=6 if minpac<minsin*6 else 1
ret=0
while n>0:
	if priority==1:
		print(n*minsin)
		exit()
	if n>=6:
		ret+=minpac
		n-=6
	else:
		ret+=min(minsin*n,minpac)
		break
print(ret)
	