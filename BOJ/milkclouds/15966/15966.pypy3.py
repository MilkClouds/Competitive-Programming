import sys
input=sys.stdin.readline

n=int(input())
d=[0]*(1000000+1)
for i in map(int,input().split()):
	d[i]=d[i-1]+1

print(max(d))