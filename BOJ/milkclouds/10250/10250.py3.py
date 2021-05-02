import sys
input=sys.stdin.readline

for _ in range(int(input())):
	h,w,n=map(int,input().split())
	y=n%h if n%h else h
	x=(n-1)//h+1
	print(100*y+x)