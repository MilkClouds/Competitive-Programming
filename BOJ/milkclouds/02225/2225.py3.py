n,k=map(int,input().split())

d=[[0]*201 for _ in range(201)]
d[0]=[1]*201
for i in range(201):
    d[i][1]=1

for i in range(1,201):
    for j in range(2,201):
        d[i][j]=sum([x[j-1] for x in d[:i+1]])%1000000000

print(d[n][k])