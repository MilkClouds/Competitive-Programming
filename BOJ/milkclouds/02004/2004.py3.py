

n,m=map(int,input().split())

def f(a):
	return a[0]-a[1]-a[2]
def t(n):
	bi=fi=0
	a=5
	while a<=n:
		fi+=n//a
		a*=5
	a=2
	while a<=n:
		bi+=n//a
		a*=2
	return bi,fi

ff=[f(i) for i in zip(t(n),t(m),t(n-m))]
print(min(ff))