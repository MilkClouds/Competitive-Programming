import sys
ii=sys.stdin.readline
for _ in range(int(ii())):
	n=int(ii())
	s=n*(n+1)//2
	ss=n*(2*n)//2
	sss=n*(2*n+2)//2
	print(s,ss,sss)