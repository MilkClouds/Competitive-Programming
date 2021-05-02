import sys
input=sys.stdin.readline

n=int(input())
graph=[[] for _ in range(n)]
degree=[0]*n
resT=[0]*n
cost=[]
for _ in range(n):
	t=list(map(int,input().split()))[:-1]
	cost.append(t[0])
	for i in t[1:]:
		graph[i-1].append(_)
		degree[_]+=1

q=[]
for i in range(n):
	if degree[i]==0: q.append(i)
	resT[i]=cost[i]

while q:
	cur=q.pop(0)
	for i in graph[cur]:
		resT[i]=max(resT[i],resT[cur]+cost[i])
		degree[i]-=1
		if degree[i]==0:
			q.append(i)

print(*resT,sep='\n')