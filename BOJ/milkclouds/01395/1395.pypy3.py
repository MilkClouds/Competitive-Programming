import sys;input=sys.stdin.readline
sys.setrecursionlimit(200000)

N,M=map(int,input().split())

class SegTree:
	def __init__(self,A,N):
		self.A=A
		self.N=N
		self.tree=[0]*4*N
		self.lazy=[0]*4*N
	def propagation(self,node,l,r):
		if self.lazy[node]==0: return
		if l!=r:
			self.lazy[node*2]^=1
			self.lazy[node*2+1]^=1
		self.tree[node]=r-l+1-self.tree[node]
		self.lazy[node]=0
	def update(self,node,l,r,s,e):
		self.propagation(node,l,r)
		if s<=l and r<=e:
			self.lazy[node]^=1
			self.propagation(node,l,r)
			return
		if e<l or r<s:
			return
		m=l+r>>1
		self.update(node*2,l,m,s,e)
		self.update(node*2+1,m+1,r,s,e)
		self.tree[node]=self.tree[node*2]+self.tree[node*2+1]
	def query(self,node,l,r,s,e):
		self.propagation(node,l,r)
		if s<=l and r<=e:
			return self.tree[node]
		if e<l or r<s:
			return 0
		m=l+r>>1
		return self.query(node*2,l,m,s,e)+self.query(node*2+1,m+1,r,s,e)

print=sys.stdout.write
A=[0]*(N+1)
Seg=SegTree(A,N)
for _ in range(M):
	cmd,*t=map(int,input().split())
	if cmd:
		print(str(Seg.query(1,1,N,*t)))
		print('\n')
	else:
		Seg.update(1,1,N,*t)