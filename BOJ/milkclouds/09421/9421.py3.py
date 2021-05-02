n=int(input())
arr=[False]*(n+1)
pn=[2]
for i in range(3,n+1,2):
	if arr[i]:continue
	pn.append(i)
	for j in range(i*i,n+1,i*2):
		arr[j]=True
arr=[False]*(600+1)
def calc(x):
	return sum([int(i)**2 for i in str(x)])
for i in pn:
	x=stop=calc(i)
	rec=[x]
	while 1:
		if arr[x]==1:
			print(i);break
		elif arr[x]==-1:
			break
		x=calc(x)
		if x==stop:
			for xx in rec:
				arr[xx]=-1
			break
		if x==1:
			for xx in rec:
				arr[xx]=1
			print(i)
			break
		rec.append(x)