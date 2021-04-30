t=list(map(int,input().split()))
r=[1,1,2,2,2,8]
print(*[i-j for i,j in zip(r,t)])