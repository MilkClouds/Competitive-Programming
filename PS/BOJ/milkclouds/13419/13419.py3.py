import sys;input=sys.stdin.readline
n=int(input())

for i in range(n):
	s=input().rstrip()
	if len(s)%2==0:
		print(s[::2],s[1::2],sep='\n')
	else:
		print(s[::2]+s[1::2],s[1::2]+s[::2],sep='\n')
