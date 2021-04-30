N=int(input())
A=[int(i) for i in input().split(' ')]
DP=A.copy()
for i in range(1,N):
	DP[i]=max(DP[i-1]+A[i],A[i])
print(max(DP))