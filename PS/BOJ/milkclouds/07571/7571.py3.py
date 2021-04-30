import sys
input=sys.stdin.readline
n,m=map(int,input().split())
x=[]
y=[]
for i in range(m):
	a,b=map(int,input().split())
	x.append(a)
	y.append(b)
x.sort()
y.sort()

medx=x[m//2]
medy=y[m//2]
xx=medx*((m+1)%2)-sum(x[:m//2])+sum(x[m//2+1:])
yy=medy*((m+1)%2)-sum(y[:m//2])+sum(y[m//2+1:])
print(xx+yy)