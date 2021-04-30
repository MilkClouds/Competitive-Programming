N,M=[int(i) for i in input().split(' ')]

roads={}
degree=[0]*N

for i in range(M):
	a,b=[int(i)-1 for i in input().split(' ')]
	roads[a]=roads.get(a,[])+[b]
	degree[b]+=1

queue=[]
for i,a in enumerate(degree):
	if not a: queue.append(i)

result=[]
while queue:
	queue.sort()
	data=queue.pop(0)
	result.append(data+1)
	for i in roads.get(data,[]):
		degree[i]-=1
		if degree[i]==0: queue.append(i)

print(' '.join(map(str,result)))	