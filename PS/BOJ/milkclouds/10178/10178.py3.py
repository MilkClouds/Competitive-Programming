import sys
input=sys.stdin.readline
for i in range(int(input())):
	a,b=map(int,input().split())
	print('You get %d piece(s) and your dad gets %d piece(s).'%divmod(a,b))