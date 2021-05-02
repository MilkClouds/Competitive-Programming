def mod(t,y):
	return t%y if t%y else y
n=int(input())
for i in range(n):
	m,n,x,y=[int(i) for i in input().split(' ')]
	a=0; qw={}; no=0
	while 1:
		g=mod((m*a+x),n)
		if g==y:
			break
		if qw.get(g,0): no=1; break
		a+=1; qw[g]=1
	print(-1 if no else m*a+x)