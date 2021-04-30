import sys;input=sys.stdin.readline
r=0;MOD=10**9+7
for _ in range(int(input())):
	c,k=map(int,input().split())
	q=k-1;t=1;p=2
	while q>0:
		if q&1: t=t*p%MOD
		p=p*p%MOD; q//=2
	r=(r+(c*k)%MOD*t)%MOD
print(r)