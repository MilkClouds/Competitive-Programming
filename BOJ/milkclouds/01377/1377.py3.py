import sys
input=sys.stdin.readline
n=int(input())
a=list(enumerate(int(input())for i in range(n)))
a.sort(key=lambda x:x[1])
r=0
for i in range(n):
	r=max(r,a[i][0]-i)
print(r+1)