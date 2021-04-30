import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline
N,M=map(int,input().split())
g=[[] for _ in range(N)]
dfsn=[0]*N
fnh=[False]*N
cnt=0
SCC=[]
stack=[]

for _ in range(M):
	a,b=map(int,input().split())
	g[a-1].append(b-1)	

def dfs(i):
	global cnt
	cnt+=1
	dfsn[i]=cnt
	stack.append(i)
	r=dfsn[i]	
	for j in g[i]:
		if not dfsn[j]:r=min(r,dfs(j))
		elif not fnh[j]:r=min(r,dfsn[j])		
	if r==dfsn[i]:
		iSCC=[]
		while True:
			t=stack.pop()
			iSCC.append(t+1)
			fnh[t]=True
			if t==i:break
		SCC.append(sorted(iSCC))	
	return r

for i in range(N):
	if not dfsn[i]:dfs(i)
print(len(SCC))
for k in sorted(SCC):print(*k,-1)