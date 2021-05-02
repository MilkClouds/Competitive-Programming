A,B,C=map(int,input().split())
l,r=0,1000000
while l<r:
    m=l+r>>1
    if A*m+B*(m//7)<C:
        l=m+1
    else:
        r=m
print(l)