import sys
input=sys.stdin.readline
INF=10**10

N=int(input())
A=list(map(int,input().split()))
M=int(input())

def update(node,l,r,i,v):
    if r<i or l>i:
        return
    if l==r:
        tree[node]=(i,v)
        return
    m=(l+r)//2
    update(node*2,l,m,i,v);
    update(node*2+1,m+1,r,i,v);
    a,b=tree[node*2],tree[node*2+1]
    if a[1]>b[1]:a,b=b,a
    tree[node]=a
    

def query(node,l,r,i,j):
    if j<l or r<i:
        return (-1,INF)
    if i<=l and r<=j:
        return tree[node]
    m=(l+r)//2
    a=query(node*2,l,m,i,j)
    b=query(node*2+1,m+1,r,i,j)
    if a[1]>b[1]:a,b=b,a
    return a

tree=[(-1,INF) for _ in range(400000)]
for idx,i in enumerate(A):
    update(1,1,N,idx+1,i)

for _ in range(M):
    cmd,i,j=map(int,input().split())
    if cmd&1:
        update(1,1,N,i,j)
    else:
        print(query(1,1,N,i,j)[0])