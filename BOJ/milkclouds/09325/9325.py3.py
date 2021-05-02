import sys
input=sys.stdin.readline
for i in range(int(input())):
	s=int(input())
	for i in range(int(input())):
		a,b=map(int,input().split())
		s+=a*b
	print(s)