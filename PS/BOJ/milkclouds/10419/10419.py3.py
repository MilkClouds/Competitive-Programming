from math import *
for i in range(int(input())):
    n=int(input())
    # t**2+t<=n<(t+1)^2
    l=0;r=10000
    while l+1<r:
        m=l+r>>1
        if m*m+m<=n:
            l=m
        else:
            r=m
    print(l)