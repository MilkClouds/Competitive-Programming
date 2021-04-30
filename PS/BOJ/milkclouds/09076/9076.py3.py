import sys
input=sys.stdin.readline
#print=sys.stdout.write
n=int(input())
for _ in range(n):
	a=sorted(map(int,input().split()))
	a.pop(0);a.pop(-1)
	print(sum(a) if a[-1]-a[0]<4 else 'KIN')