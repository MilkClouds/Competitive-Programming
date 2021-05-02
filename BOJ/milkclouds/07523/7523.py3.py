import sys
input=sys.stdin.readline
for i in range(int(input())):
	m,n=map(int,input().split())
	print('Scenario #%d:\n%d\n'%(i+1,(n-m+1)*(m+n)//2))