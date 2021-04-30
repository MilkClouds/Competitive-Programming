N,K=map(int,input().split())

A=[1]
for i in range(2,N//2+1):
    if N%i==0: A.append(i)

# print(len(A))
A.append(N)
if len(A)<K: print(0)
else: print(A[K-1])