import sys;input=sys.stdin.readline
sys.setrecursionlimit(200000)

n,m=map(int,input().split())
save=[0]*(n+1)
ans=[0]*(n+1)

childs=[[] for _ in range(n+1)]
for idx,i in enumerate(map(int,input().split())):
	if ~i:childs[i].append(idx+1)

for _ in range(m):
	t,w=map(int,input().split())
	save[t]+=w

prop=0
def dfs(cur):
	global prop
	prop+=save[cur]
	ans[cur]=prop
	for i in childs[cur]:
		dfs(i)
	prop-=save[cur]

dfs(1)
print(*ans[1:])