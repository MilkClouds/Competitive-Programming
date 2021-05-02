D=[1,0]+[0]*29
for i in range(2,31,2):
	D[i]=D[i-2]*3+sum([D[i-4-k]*2 for k in range(0,i-4+1,2)])
print(D[int(input())])