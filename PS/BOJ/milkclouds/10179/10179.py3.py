import sys
input=sys.stdin.readline
for i in range(int(input())):
	a=float(input())
	print('$%.2f'%round(a*.8,2))