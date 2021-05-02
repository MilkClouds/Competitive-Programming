import sys
input=sys.stdin.readline

n=int(input())
for i in range(n):
	input()
	a=list(map(int,input().split()))
	s=0; m=-1000
	for i in a:
		s+=i
		if m<s: m=s
		if s<0: s=0
	print(m)