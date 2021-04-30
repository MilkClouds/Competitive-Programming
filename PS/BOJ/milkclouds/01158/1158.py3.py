N,M=[int(i) for i in input().split(' ')]

queue=list(range(1,N+1))

p=0; ans=[]
while queue:
	p=(p+M-1)%len(queue)
	ans.append(queue.pop(p))
print('<%s>'%(', '.join(map(str,ans))))