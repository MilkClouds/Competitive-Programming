import sys
input=sys.stdin.readline

V=int(input())
E=int(input())
g=[[0]*V for _ in range(V)]
for _ in range(E):
	a,b=map(int,input().split())
	a-=1;b-=1
	g[a][b]=1
	g[b][a]=1

t=set()
from collections import deque
q=deque()
q.append(0)
t.add(0)

while q:
	c=q.popleft()
	for i in range(V):
		if g[c][i]:
			if i not in t:
				q.append(i)
				t.add(i)
print(len(t)-1)
