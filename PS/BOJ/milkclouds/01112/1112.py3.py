a,b=map(int,input().split())
ret=''
flag=0
def divmod_(a,b):
	if b<0:
			mod=a%-b
			return (a-mod)//b,mod
	return divmod(a,b)
if a<0 and b>0:
	flag=1
	a=-a
while a:
	a,y=divmod_(a,b)
	ret=str(y)+ret
if ret:
	if flag:
		print('-'+ret)
	else:
		print(ret)
else:
	print(0)