import sys
from bisect import insort
input=sys.stdin.readline
n=int(input())

c=0;limit=n*n-n;li=[]
for i in range(n):
	for x in map(int,input().split()):
		insort(li,x)
		if len(li)>n:
			del li[0]
print(li[0])