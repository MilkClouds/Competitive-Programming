n=int(input())
A=[list(input().split()) for i in range(n)]
score=[0]*n
for tt in zip(*A):
    check={}
    for i in range(n):
        check[tt[i]]=check.get(tt[i],0)+1
    for i in range(n):
        if check[tt[i]]==1:
            score[i]+=int(tt[i])

print(*score,sep='\n')
