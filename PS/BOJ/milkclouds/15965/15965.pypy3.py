max=4000000
A=[1]*max;pn=[2]
for i in range(3,max+1,2):
	if not A[i]: continue
	pn.append(i)
	for e in range(i*i,max+1,i*2):
		A[e]=0
print(pn[int(input())-1])