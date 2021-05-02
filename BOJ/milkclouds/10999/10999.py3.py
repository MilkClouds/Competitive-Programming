import sys;input=sys.stdin.readline

N,M,K=map(int,input().split())
A=[int(input()) for _ in range(N)]

class SegTree:
    def init(self,node,left,right):
        if left+1==right:
            self.tree[node]=self.A[left]
        else:
            mid=(left+right)//2
            self.tree[node]=self.init(node*2,left,mid)+self.init(node*2+1,mid,right)
        return self.tree[node]

    def __init__(self,N,A):
        self.A=A
        self.tree=[0]*4*N
        self.lazy=[0]*4*N
        self.init(1,0,N)

    def sum(self,node,left,right,start,end):
        self.propagation(node,left,right)
        if start<=left and right<=end:
            return self.tree[node]
        if right<=start or end<=left:
            return 0
        mid=(left+right)//2
        return self.sum(node*2,left,mid,start,end)+self.sum(node*2+1,mid,right,start,end)

    def propagation(self,node,start,end):
        if self.lazy[node]==0: return
        self.tree[node]+=self.lazy[node]*(end-start)
        if start+1!=end:
            self.lazy[node*2]+=self.lazy[node]
            self.lazy[node*2+1]+=self.lazy[node]
        self.lazy[node]=0

    def update(self,node,left,right,start,end,value):
        self.propagation(node,left,right)
        if start<=left and right<=end:
            self.tree[node]+=(right-left)*value
            if left+1!=right:
                self.lazy[node*2]+=value
                self.lazy[node*2+1]+=value
            return
        if right<=start or end<=left:
            return
        mid=(left+right)//2
        self.update(node*2,left,mid,start,end,value)
        self.update(node*2+1,mid,right,start,end,value)
        self.tree[node] = self.tree[node*2] + self.tree[node*2+1]


Seg1=SegTree(N,A)

for _ in range(M+K):
    it=map(int,input().split())
    if next(it)==2:
        b,c=it
        print(Seg1.sum(1,0,N,b-1,c))
    else:
        b,c,d=it
        Seg1.update(1,0,N,b-1,c,d)