import sys
input=sys.stdin.readline

t=0
for i in range(int(input())):
	a,b=map(int,input().split())
	t+=b%a
print(t)