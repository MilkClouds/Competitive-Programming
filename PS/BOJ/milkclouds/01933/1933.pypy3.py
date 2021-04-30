import sys
input=sys.stdin.readline
print=sys.stdout.write
N=int(input())
a=[];yy=[]
for _ in range(N):
    l,h,r=map(int,input().split())
    a.append((l,h,1))
    a.append((r,h,-1))
    yy.append(h)

a.sort(key=lambda x:x[0])
yy.sort()
idx={}
for i,j in enumerate(yy):
    idx[j]=i
tree=[0]*400000

def update(node,l,r,i,v):
    if r<i or l>i:
        return (yy[l] if tree[node] else 0) if l==r else tree[node]
    if l==r:
        tree[node]+=v
        return yy[i] if tree[node] else 0
    m=(l+r)//2
    tree[node]=max(update(node*2,l,m,i,v),update(node*2+1,m+1,r,i,v))
    return tree[node]
prev=0
for j in range(2*N):
    x,y,flag=a[j]
    M=update(1,0,N-1,idx[y],flag)
    if j+1<2*N and a[j+1][0]==x:
        continue
    if M^prev:
        print("%d %d "%(x,M))
    prev=M