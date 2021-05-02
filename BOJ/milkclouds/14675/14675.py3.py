import sys
input=sys.stdin.readline
V=N=int(input())
edges=[]
adj=[set() for i in range(V+1)]
for _ in range(N-1):
    a,b=map(int,input().split())
    edges.append((a,b))
    adj[a].add(b)
    adj[b].add(a)

discovered=[0]*(N+1)
isCutV=[False]*(N+1)
idx=0
def dfsV(node,isRoot):
    global idx
    idx+=1
    discovered[node]=ret=idx
    cnt=0
    for i in adj[node]:
        if discovered[i]:
            ret=min(ret,discovered[i])
            continue
        cnt+=1
        prev=dfsV(i,False)
        ret=min(ret,prev)
        if discovered[node]<=prev and not isRoot:
            isCutV[node]=1
    if isRoot and cnt>1:
        isCutV[node]=1
    return ret
for i in range(1,1+V):
    discovered[i] or dfsV(i,True)
discovered=[0]*(N+1)
isCutE=[{} for _ in range(N+1)]
idx=0
def dfsE(node,parent=0):
    global idx
    idx+=1
    discovered[node]=ret=idx
    for i in adj[node]:
        if i==parent: continue
        if discovered[i]:
            ret=min(ret,discovered[i])
            continue
        prev=dfsE(i,node)
        ret=min(ret,prev)
        if discovered[node]<prev:
            a,b=sorted([node,i])
            isCutE[a][b]=1
    return ret
for i in range(1,1+V):
    discovered[i] or dfsE(i,0)

q=int(input())
for _ in range(q):
    t,k=map(int,input().split())
    if t==1:
        print('yes' if isCutV[k] else 'no')
    else:
        a,b=sorted(edges[k-1])
        print('yes' if isCutE[a].get(b) else 'no')