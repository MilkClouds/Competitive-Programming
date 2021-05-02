import sys
i=sys.stdin.readline
for _ in range(int(i())):
	n=int(i())
	n=n if n&1 else n-1
	print((n+1)//2*(1+n)//2)