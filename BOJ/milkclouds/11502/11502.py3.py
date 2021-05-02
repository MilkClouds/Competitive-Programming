import sys
ii=sys.stdin.readline
arr=[0]*1000;pn=[2]
for i in range(3,1000,2):
	if arr[i]:continue
	pn.append(i)
	for j in range(i*i,1000,i*2):
		arr[j]=1
arr=[0]*1000
for i in pn:
	arr[i]=1
for _ in range(int(ii())):
	n=int(ii());br=0
	for i in pn:
		if br:break
		for j in pn:
			if arr[n-i-j]:
				print(*sorted((i,j,n-i-j)))
				br=1
				break
	if not br:print(0)