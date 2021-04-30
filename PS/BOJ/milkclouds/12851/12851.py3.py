from collections import deque
n,k=map(int,input().split())
if n>k:
	print(n-k)
	print(1)
	exit()
deq=deque()
deq.append((n,0))
MAX=130000
visit=[[MAX,1] for _ in range(MAX+1)]
visit[n][0]=0
def a(n,c,p):
	if 0<=n<=MAX:
		if visit[n][0]==c:
			visit[n][1]+=visit[p][1]
		elif visit[n][0]>c:
			visit[n]=[c,visit[p][1]]
			deq.append((n,c))
while deq:
	n,c=deq.popleft()
	if c>visit[k][0]:break
	c+=1
	a(n+1,c,n)
	a(n-1,c,n)
	a(n*2,c,n)
print(*visit[k],sep='\n')