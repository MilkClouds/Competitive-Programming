
while 1:
	a,b,c,d=map(int,input().split())
	if (a,b,c,d)==(0,0,0,0):
		exit()
	x,y,z,w=a,b,c,d;index=0
	if a==b==c==d: print(0);continue
	while 1:
		index+=1
		x,y,z,w=abs(x-y),abs(y-z),abs(z-w),abs(w-x)
		#print(x,y,z,w)
		if x==y==z==w:
			break
	print(index)