import sys
input=sys.stdin.readline

k=int(input())
c=int(input())
for i in range(c):
	m,n=map(int,input().split())
	if m>n:
		if n+(k-m+1)<m-1:
			print(0)
		else:print(1)
	else:
		if m+(k-n)<n-1:
			print(0)
		else:print(1)