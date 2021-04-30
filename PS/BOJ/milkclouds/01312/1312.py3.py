a,b,n=map(int,input().split())
a=a%b
while n:
	a*=10
	c=a//b
	a%=b
	n-=1
print(c)