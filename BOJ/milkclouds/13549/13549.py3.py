from collections import deque

n,k=map(int,input().split())
if n>k:
	print(n-k)
	exit()

deq=deque()
MAX=130000
visit=[0 for _ in range(MAX+1)]
def a(n,c):
	if 0<=n<=MAX:
		if not visit[n]:
			visit[n]=True
			deq.append((n,c))
			if n==k:
				print(c)
				exit()
a(n,0)
while deq:
	n,c=deq.popleft()
	r=n
	if r:
		while exec('r*=2') or r<=MAX:
			a(r,c)
	c+=1
	a(n+1,c)
	a(n-1,c)