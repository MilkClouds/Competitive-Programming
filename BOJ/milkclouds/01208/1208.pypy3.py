N,S=map(int,input().split())
T=list(map(int,input().split()))
A,B=T[:N//2],T[N//2:]
a,b=len(A),len(B)
tableA,tableB={},{}
ans=0
for i in range(1,1<<a):
    t=sum(A[e] for e in range(a) if i&(1<<e))
    tableA[t]=tableA.get(t,0)+1
for i in range(1,1<<b):
    t=sum(B[e] for e in range(b) if i&(1<<e))
    tableB[t]=tableB.get(t,0)+1
for i in tableA:
    if tableB.get(S-i):
        ans+=tableB[S-i]*tableA[i]
print(tableA.get(S,0)+tableB.get(S,0)+ans)