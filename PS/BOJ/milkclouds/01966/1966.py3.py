T=int(input())
for i in range(T):
	N,c=[int(i) for i in input().split(' ')]
	queue=[]; index=0
	queue=[int(i) for i in input().split(' ')]
	while queue:
		i=queue.pop(0)
		if queue and max(queue)>i:
			if c==0: c=len(queue)
			else: c-=1
			queue.append(i)
		else:
			if c==0: index+=1; break
			else: c-=1; index+=1
	print(index)