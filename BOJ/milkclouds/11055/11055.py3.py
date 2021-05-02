N=int(input())
A=list(map(int,input().split(' ')))
d=[0 for i in range(N)]
d=A.copy()
ans=0

for i,a in enumerate(A):
    for j,b in enumerate(A[:i]):
        if A[i]>A[j]:
            d[i]=max(d[j]+A[i],d[i])
    ans=max(d[i],ans)

print(ans)