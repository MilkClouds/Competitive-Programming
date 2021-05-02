import sys
input=sys.stdin.readline

n,m,v=map(int,input().split())
v-=1

road=[[0]*n for _ in range(n)]
arr=[v]

for _ in range(m):
	a,b=map(lambda x:int(x)-1,input().split())
	road[a][b]=1
	road[b][a]=1

BFS=[];DFS=[];visited=[0]*n
while arr:
	cur=arr.pop()
	if visited[cur]: continue
	DFS.append(cur+1)
	visited[cur]=1
	le=len(road[cur])
	for i,e in enumerate(road[cur][::-1]):
		i=le-i-1
		if e==1 and not visited[i]:
			arr.append(i)
	
arr=[v];visited=[0]*n
while arr:
	cur=arr.pop(0)
	if visited[cur]: continue
	BFS.append(cur+1)
	visited[cur]=1
	for i,e in enumerate(road[cur]):
		if e==1 and not visited[i]:
			arr.append(i)
print(*DFS)
print(*BFS)