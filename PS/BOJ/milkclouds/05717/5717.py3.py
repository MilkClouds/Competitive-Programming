import sys
input=sys.stdin.readline
while 1:
	a,b=map(int,input().split())
	if a==b==0: exit()
	print(a+b)