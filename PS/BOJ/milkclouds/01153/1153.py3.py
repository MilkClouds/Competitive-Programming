n=int(input())

arr=[1]*1000000
pn=[2]
for i in range(3,1000000,2):
	if arr[i]==0: continue
	pn.append(i)
	for e in range(i*i,1000000,i*2):
		arr[e]=0
arr=[0]*1000000
for i in pn:arr[i]=1

ans=[]
for i in range(2,n):
	if not arr[i]:continue
	for j in range(2,n-i):
		if not arr[j]:continue
		for k in range(2,n-i-j):
			if not arr[k]:continue
			if arr[n-i-j-k]:
				ans=[i,j,k,n-i-j-k]
				break
		if ans:break
	if ans:break
if ans:
	print(*sorted(ans))
else:print(-1)