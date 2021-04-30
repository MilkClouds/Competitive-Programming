N=int(input())
A=[int(input()) for i in range(N)]
DP=[1]*N
for i in range(N):
    for j in range(i):
        if A[i]>A[j]:
            DP[i]=max(DP[j]+1,DP[i])
print(N-max(DP))