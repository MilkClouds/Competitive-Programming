from heapq import *
import sys;input=sys.stdin.readline
heap=[]
V,E=map(int,input().split())

ranks=[1]*(V+1)
par=[i for i in range(V+1)]
def find(u):
    if par[u]==u: return u
    par[u]=find(par[u])
    return par[u]
def merge(u,v):
    u=find(u);v=find(v)
    if ranks[u]<ranks[v]: u,v=v,u
    par[v]=u
    if ranks[u]==ranks[v]: ranks[u]+=1

for _ in range(E):
    A,B,C=map(int,input().split())
    heappush(heap,(C,A,B))

ans=0
while heap:
    C,A,B=heappop(heap)
    if find(A)!=find(B):
        merge(A,B)
        ans+=C
print(ans)