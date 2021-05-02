import sys
sys.setrecursionlimit(30003)
input=sys.stdin.readline
n=int(input())
nodes=[[] for i in range(n)]
dist=[{} for i in range(n)]
for _ in range(n-1):
	p,c,d=map(int,input().split())
	p-=1;c-=1
	nodes[p].append(c)
	dist[p][c]=d

maxheight=0
def solve(parent):
	global maxheight
	if nodes[parent]==[]:
		return 0
	height=[]
	for child in nodes[parent]:
		height.append(solve(child)+dist[parent][child])
	height.sort(reverse=1)
	if len(height)>=2:
		maxheight=max(maxheight,height[0]+height[1])
	return height[0]

t=solve(0)
print(max(t,maxheight))