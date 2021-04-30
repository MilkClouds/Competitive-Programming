import sys
input()
def lc(a,b):
	if a<b:a,b=b,a
	c=b;d=a
	while a%b:
		a,b=b,a%b
	return c*d//b
for l in sys.stdin:
	a,b=map(int,l.split())
	print(lc(a,b))