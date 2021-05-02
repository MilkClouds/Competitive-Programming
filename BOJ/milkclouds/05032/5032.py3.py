a,b,c=map(int,input().split())
a+=b
ret=0
while a>=c:
	ret+=a//c
	a=a//c+a%c
print(ret)