import sys
input=sys.stdin.readline
for _ in range(int(input())):
	d=[input().split() for i in range(int(input()))]
	r=max(d,key=lambda x:int(x[1]))
	print(r[0])