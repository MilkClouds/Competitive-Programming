N,M=map(int,input().split())
A=[0]*N
for _ in range(M):
	i,j,k=map(int,input().split())
	A[i-1:j]=[k]*(j-i+1)
print(*A)