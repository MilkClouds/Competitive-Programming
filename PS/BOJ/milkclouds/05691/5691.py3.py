import sys
for line in sys.stdin:
	a,b=map(int,line.split())
	if (a,b)==(0,0):exit()
	if a>b:a,b=b,a
	c=2*a-b
	c=min(c,2*b-a)
	if (a+b)%2==0:
		c=min(c,(a+b)//2)
	print(c)