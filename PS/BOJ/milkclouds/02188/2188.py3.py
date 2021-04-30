import sys
input=sys.stdin.readline

N,M=map(int,input().split())

home=[False]*N
for i in range(N):
	home[i]=list(map(lambda x:int(x)-1,input().split()))[1:]

home_to_cow=[-1]*M
def dfs(cow):
	if visited.get(cow): return False
	visited[cow]=True
	for i in home[cow]:
		if home_to_cow[i]==-1 or dfs(home_to_cow[i]):
			home_to_cow[i]=cow
			return True
	return False

ret=0
for cow in range(N):
	visited={}
	if dfs(cow):
		ret+=1

print(ret)