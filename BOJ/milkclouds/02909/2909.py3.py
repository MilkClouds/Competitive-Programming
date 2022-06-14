def f(x,r):
	t=x//10**(r-1)
	if t%10>=5: t+=10-t%10
	return (t//10)*10**r

a,b=map(int,input().split())
print(f(a,b) if b else a)