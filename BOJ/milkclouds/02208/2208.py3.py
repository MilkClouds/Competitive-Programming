import sys
input=sys.stdin.readline

n,m=map(int,input().split())

a=[int(input()) for _ in range(n)]

pSum=[0]
for i in range(n):
	pSum.append(pSum[i]+a[i])

temp=10**10;ret=0
for i in range(m-1,n):
	temp=min(temp,pSum[i-m+1])
	ret=max(ret,pSum[i+1]-temp)

print(ret)

