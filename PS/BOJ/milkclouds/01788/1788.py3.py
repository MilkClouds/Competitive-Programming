import sys
input=sys.stdin.readline

#n,m=map(int,input().split())
n=int(input())

d={}
d[0]=0
d[1]=1
mod=10**9
def func(n):
	if n>=0: return n%mod
	else: return -((-n)%mod)
if n>=0:
	for i in range(2,n+1):
		d[i]=(d[i-1]+d[i-2])%mod
	print(0 if n==0 else 1)
	print(d[n])
else:
	for i in range(1,n,-1):
		d[i-2]=func(d[i]-d[i-1])
	print(0 if d[n]==0 else (1 if d[n]>0 else -1))
	print(abs(d[n]))