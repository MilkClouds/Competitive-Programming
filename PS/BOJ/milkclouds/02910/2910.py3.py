import sys
input=sys.stdin.readline
n,c=map(int,input().split())
d={};r={};idx=1
for i in map(int,input().split()):
	d[i]=d.get(i,0)+1
	idx+=1
t=sorted(d.items(),reverse=1,key=lambda x:x[1])
for i,j in t:
	for e in range(j):
		print(i,end=' ')