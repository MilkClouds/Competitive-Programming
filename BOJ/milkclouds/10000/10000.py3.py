import sys
from bisect import *
input=sys.stdin.readline
sys.setrecursionlimit(400000)

n=int(input())
a=[]
for i in range(n):
	x,r=map(int,input().split())
	a.append((x-r,x+r))
a.sort(key=lambda x:(x[0],-x[1]))
k=0
def solve(u,v):
	global k
	if a[u][1]==a[v][1]:
		k+=1
		return
	pos=bisect_left(a,(a[v][1],-2e9))
	if pos==len(a):return
	if a[pos][0]==a[v][1]:
		solve(u,pos)
for i in range(n-1):
	if a[i][0]==a[i+1][0]:
		solve(i,i+1)
print(n+k+1)