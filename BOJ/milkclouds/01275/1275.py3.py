import sys
input=sys.stdin.readline
n,q=map(int,input().split())
A=[0]+list(map(int,input().split()))
tree=[0]*(n+1)
def update(u,v):
	while u<=n:
		tree[u]+=v
		u+=u&-u
def query(x):
	r=0
	while x:
		r+=tree[x]
		x&=x-1
	return r
for u,v in enumerate(A):
	u and update(u,v)
for _ in range(q):
	x,y,a,b=map(int,input().split())
	if x>y:x,y=y,x
	print(query(y)-query(x-1))
	update(a,b-A[a])
	A[a]=b