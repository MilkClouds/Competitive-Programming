N=int(input())
A=[int(i) for i in input().split(' ')]
DP=[1]*N;DP2=[1]*N
for i in range(N):
    for j in range(i):
        if A[i]>A[j]:
            DP[i]=max(DP[j]+1,DP[i])
B=A.copy()
B.reverse()
for i in range(N):
    for j in range(i):
        if B[i]>B[j]:
            DP2[i]=max(DP2[j]+1,DP2[i])

print(max([sum(i) for i in zip(DP,DP2[::-1])])-1)