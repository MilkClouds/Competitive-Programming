a,b,c,d=map(int,input().split())
for i in map(int,input().split()):
	x=i%(a+b)
	y=i%(c+d)
	r=0
	r+=1 if 0<x<=a else 0
	r+=1 if 0<y<=c else 0
	print(r)