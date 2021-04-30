import sys

for n,line in enumerate(sys.stdin):
	l=list(map(int,line.split()))
	a,b,c=l
	if a==b==c==0:exit()
	for s in ('a','b','c'):
		if eval(s)==-1:
			break
	if s=='c': c=(a**2+b**2)**.5
	elif s=='a': a=(c*c-b*b)**.5
	else: b=(c*c-a*a)**.5
	print("Triangle #%d"%(n+1))
	if not ((a+b+c).imag) and a+b>c:
		print("%s = %.3f"%(s,eval(s)))
	else:print('Impossible.')
	print()