N=int(input())

D=[0,1,2]

if N<3: print(D[N])
else:
	a,b=D[1:]
	for i in range(N-2):
		a,b=(b,(a+b)%15746)
	print(b)