N,S=[int(i) for i in input().split(' ')]
A=[int(i) for i in input().split(' ')]
c=0
for i in range(1,1<<N):
    r=sum([A[e] for e in range(N) if i&(1<<e)])
    c+=1 if(r==S) else 0
print(c)