N=int(input())
A=[int(i) for i in input().split(' ')]

D=[1 for i in range(N)]

for i,a in enumerate(A):
    for j,b in enumerate(A[:i]):
        if A[i]>A[j]:
            D[i]=max(D[j]+1,D[i])
print(max(D))