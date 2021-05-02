n=int(input())
a=list(map(int,input().split()))

x=y=0
for i in a:
	x+=10*(i//30+1)
	y+=15*(i//60+1)
if x==y:
	print('Y M',x)
else:
	print('M' if x>y else 'Y',min(x,y))