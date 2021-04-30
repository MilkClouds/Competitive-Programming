n=int(input())
l,r=0,5*10**8

def f(n):
	r=0
	while(n):
		r+=n//5
		n//=5
	return r

while(l+1<r):
	m=(l+r)//2
	if f(m)>=n:
		r=m
	else:
		l=m

print(r if f(r)==n else -1)