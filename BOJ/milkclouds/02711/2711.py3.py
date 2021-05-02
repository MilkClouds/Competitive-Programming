import sys
input=sys.stdin.readline
for _ in range(int(input())):
	a,b=input().split()
	c=list(b)
	c.pop(int(a)-1)
	print(*c,sep='')