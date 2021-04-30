a,b=map(int,input().split())
arr=[1]*(b+1)
pn = []
if b>2: pn.append(2)
for i in range(3,b,2):
	if not arr[i]:continue
	pn.append(i)
	for j in range(i*i,b,i*2):arr[j]=0

for i in pn:
	if a%i==0:
		print('BAD',i)
		exit()
	
print('GOOD')