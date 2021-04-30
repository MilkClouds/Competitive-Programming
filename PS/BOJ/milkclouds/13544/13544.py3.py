import sys;input=sys.stdin.readline
from bisect import *
N=int(input())
A=list(map(int,input().split()))

class SegTree:
    def init(self,node,left,right):
        if left==right:
            self.tree[node]=[self.A[left-1]]
        else:
            mid=(left+right)//2
            A=self.init(node*2,left,mid)
            B=self.init(node*2+1,mid+1,right)
            self.tree[node]=sorted(A+B)
        return self.tree[node]
    def __init__(self,A,N):
        self.N=N
        self.A=A
        self.tree=[0]*4*N
        self.init(1,1,N)
    def query(self,node,left,right,i,j,k):
        if i<=left and right<=j:
            return len(self.tree[node])-bisect(self.tree[node],k)
        if j<left or right<i:
            return 0
        mid=(left+right)//2
        return self.query(node*2,left,mid,i,j,k)+self.query(node*2+1,mid+1,right,i,j,k)

Seg=SegTree(A,N)
last_ans=0
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    i=a^last_ans
    j=b^last_ans
    k=c^last_ans
    last_ans=Seg.query(1,1,N,i,j,k)
    print(last_ans)