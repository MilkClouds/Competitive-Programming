from fractions import Fraction
p,q=map(int,input().split())
m=0;t=p;tt=0
for i in range(q):
	tt=int(str(t)[::-1])
	m=max(m,tt)
	t+=p
print(m)