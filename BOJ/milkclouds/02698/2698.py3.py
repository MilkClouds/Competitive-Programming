# n k last
# 101 100 2
# n k 0=n-1 k 0+n-1 k 1
# n k 1=n-1 k 0+n-1 k-1 1
import sys
input=sys.stdin.readline

d=[[[0]*2 for i in range(100)] for i in range(101)]

n=100
d[1][0]=[1,1]
if 1:
	for i in range(2,1+n):
		for j in range(i):
			d[i][j][0]=d[i-1][j][0]+d[i-1][j][1]
			d[i][j][1]=d[i-1][j][0]+d[i-1][j-1][1]

for _ in range(int(input())):
	n,k=map(int,input().split())
	print(sum(d[n][k]))
			