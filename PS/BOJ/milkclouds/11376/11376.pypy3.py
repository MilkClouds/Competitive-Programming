import sys
input=sys.stdin.readline
N,M=map(int,input().split())
flow=['']
for i in range(N):
 t=list(map(int,input().split()))[1:]
 flow.append(t)
 flow.append(t)
rev=[0]*1005
def dfs(n):
 if visited[n]: return 0
 visited[n]=1
 for i in flow[n]:
  if not rev[i] or dfs(rev[i]):
   rev[i]=n
   return 1
ret=0
for i in range(N*2):
 visited=[0]*2005
 if dfs(1+i):ret+=1
print(ret)