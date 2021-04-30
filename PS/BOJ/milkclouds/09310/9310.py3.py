import sys
input=sys.stdin.readline
while 1:
	n=int(input())
	if not n:break
	a=list(map(int,input().split()));b=a[0]
	if a[2]+a[0]==2*a[1]:
		print(n*(2*b+(n-1)*(a[1]-b))//2)
	else:
		r=a[1]//a[0]
		print(b*(r**n-1)//(r-1))