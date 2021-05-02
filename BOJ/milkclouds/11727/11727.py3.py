D=[1,1,3]
N=int(input())
for i in range(3,N+1):
	D.append((D[i-1]+D[i-2]*2)%10007)
	
print(D[N])