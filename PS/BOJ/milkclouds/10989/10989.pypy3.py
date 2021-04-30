import sys
input=sys.stdin.readline
N=int(input())
a=[0 for i in range(10000)]
for i in range(N):
	a[int(input())-1]+=1

for i,data in enumerate(a):
	print((str(i+1)+'\n')*data,end='')