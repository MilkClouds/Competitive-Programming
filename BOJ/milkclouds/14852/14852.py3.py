N=int(input())
MOD=1000000007

D=[1,2,7,22]
D2=[0,0,0,1]
for i in range(4,N+1):
    D2.append((D2[i-1]+D[i-3])%MOD)
    D.append((3*D[i-2]+2*D[i-1]+2*D2[i])%MOD)

print(D[N])