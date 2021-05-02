import sys;input=sys.stdin.readline
sys.setrecursionlimit(200000)
V,E=map(int,input().split())
adj=[set() for _ in range(100001)]
for _ in range(E):
	a,b=map(int,input().split())
	adj[a].add(b)
	adj[b].add(a)

discovered=[0]*100001
isCut=set()
idx=0
def dfs(node,parent=0):
	global idx
	idx+=1
	discovered[node]=ret=idx
	for i in adj[node]:
		if i==parent: continue
		if discovered[i]:
			ret=min(ret,discovered[i])
			continue
		prev=dfs(i,node)
		ret=min(ret,prev)
		if discovered[node]<prev:
			isCut.add(tuple(sorted([node,i])))
	return ret

for i in range(1,1+V):
	discovered[i] or dfs(i,0)
isCut=sorted(isCut)
print(len(isCut))
[*map(print,*zip(*isCut))]