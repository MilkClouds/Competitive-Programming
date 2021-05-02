import sys
input=sys.stdin.readline
for di in range(1,10**8):
	a,b,m,x=map(int,input().split())
	if a==b==m==x==0:
		exit()
	s={}
	s[x]=0
	for i in range(1,10**8):
		x=(a*x+b)%m
		if s.get(x,-1)!=-1:
			print('Case %d: %d'%(di,i-s[x]))
			break
		s[x]=i