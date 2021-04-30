def ad(a,b):
	global x,y
	x+=a;y+=b
while 1:
	i=input()
	if i=='0': exit()
	l=list(map(int,i.split()))
	a,b=l[0],l[1:]
	b.sort()
	nozero=list(map(str,filter(lambda x:x!=0,b)))
	b=list(map(str,b))
	x=nozero[0]
	y=nozero[1]
	b.remove(nozero[0])
	b.remove(nozero[1])
	if a&1:	
		x+=b[0];b.pop(0)
		[*map(ad,*2*[iter(b)])]
		print(int(x)+int(y))
	else:
		[*map(ad,*2*[iter(b)])]
		print(int(x)+int(y))