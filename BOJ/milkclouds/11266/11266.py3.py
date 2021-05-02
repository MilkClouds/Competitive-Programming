import sys;input=sys.stdin.readline
sys.setrecursionlimit(99999)
V,E=map(int,input().split())
adj=[set() for _ in range(10002)]
for _ in range(E):
	a,b=map(int,input().split())
	adj[a].add(b)
	adj[b].add(a)

discovered=[0]*10002
isCut=set()
idx=0
def dfs(node,isRoot):
	global idx
	idx+=1
	discovered[node]=ret=idx
	cnt=0
	for i in adj[node]:
		if discovered[i]:
			ret=min(ret,discovered[i])
			continue
		cnt+=1
		prev=dfs(i,False)
		ret=min(ret,prev)
		if discovered[node]<=prev and not isRoot:
			isCut.add(node)
	if isRoot and cnt>1:
		isCut.add(node)
	return ret

for i in range(1,1+V):
	discovered[i] or dfs(i,True)

print(len(isCut))
print(*sorted(isCut))