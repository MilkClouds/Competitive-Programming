a=b=100
for i in range(int(input())):
	x,y=map(int,input().split())
	if x>y: b-=x
	elif x<y: a-=y
print(a,b,sep='\n')