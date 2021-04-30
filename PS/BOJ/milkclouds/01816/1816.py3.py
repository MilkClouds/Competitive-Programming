arr=[False]*(10**6+1)
pn=[2]
for i in range(3,10**6+1,2):
	if arr[i]:continue
	pn.append(i)
	for j in range(i*i,10**6+1,i*2):
		arr[j]=True

for _ in range(int(input())):
	n=int(input());no=0
	for i in pn:
		if n%i==0:
			no=1
			print('NO')
			break
	if not no:print('YES')