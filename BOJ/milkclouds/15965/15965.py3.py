max=8000000
A=[True]*max;pn=[2]
for i in range(3,max+1,2):
	if not A[i]: continue
	pn.append(i)
	for e in range(i*i,max+1,i*2):
		A[e]=False
print(pn[int(input())-1])