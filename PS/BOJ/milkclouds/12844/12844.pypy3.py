import sys;input=sys.stdin.readline
sys.setrecursionlimit(200000)

N=int(input())
A=list(map(int,input().split()))

class SegTree:
	def init(self,node,l,r):
		if l==r:
			self.tree[node]=A[l]
		else:
			m=(l+r)//2
			a=self.init(node*2,l,m)
			b=self.init(node*2+1,m+1,r)
			self.tree[node]=a^b
		return self.tree[node]
	def __init__(self,A,N):
		self.A=A
		self.N=N
		self.tree=[0]*4*N
		self.lazy=[0]*4*N
		self.init(1,0,N-1)
	def propagation(self,node,l,r):
		if self.lazy[node]==0: return
		if l!=r:
			self.lazy[node*2]^=self.lazy[node]
			self.lazy[node*2+1]^=self.lazy[node]
		if (r-l+1)&1:
			self.tree[node]^=self.lazy[node]
		self.lazy[node]=0
	def update(self,node,l,r,s,e,v):
		self.propagation(node,l,r)
		if s<=l and r<=e:
			self.lazy[node]^=v
			self.propagation(node,l,r)
			return
		if e<l or r<s:
			return
		m=(l+r)//2
		self.update(node*2,l,m,s,e,v)
		self.update(node*2+1,m+1,r,s,e,v)
		self.tree[node]=self.tree[node*2]^self.tree[node*2+1]
	def query(self,node,l,r,s,e):
		self.propagation(node,l,r)
		if s<=l and r<=e:
			return self.tree[node]
		if e<l or r<s:
			return 0
		m=(l+r)//2
		return self.query(node*2,l,m,s,e)^self.query(node*2+1,m+1,r,s,e)

print=sys.stdout.write
Seg=SegTree(A,N)
for _ in range(int(input())):
	cmd,*t=map(int,input().split())
	if cmd==2:
		t.sort()
		print(str(Seg.query(1,0,N-1,*t)))
		print('\n')
	else:
		s,e,v=t
		if s>e: s,e=e,s
		Seg.update(1,0,N-1,s,e,v)