import sys
input=sys.stdin.readline
n,k=map(int,input().split())
ret=0
for i in map(int,input().split()):
	ret+=(1+i)//2

print('YES' if ret>=n else 'NO')