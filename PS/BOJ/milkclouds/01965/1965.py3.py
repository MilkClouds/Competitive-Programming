N=int(input())
A=[int(i) for i in input().split(' ')]

DP=[1]*N
for i in range(N):
    for j in range(i):
        if A[i]>A[j]:
            DP[i]=max(DP[j]+1,DP[i])

print(max(DP))