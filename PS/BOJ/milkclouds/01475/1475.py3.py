N=int(input())

A=[0]*10

for i in str(N):
	A[int(i)]+=1

B=A.copy()
del B[9],B[6]
B.append((A[6]+A[9]+1)//2)
print(max(B))