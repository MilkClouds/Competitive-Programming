from decimal import *
a=[1,5]

for i in range(1,1000):
    a.append((a[i]*6-a[i-1]*4+1)%1000)

for i in range(int(input())):
    n=int(input())
    if n<103:
        ans=a[n]
    else:
        n%=100
        if n<3: n+=100
        ans=a[n]
    print("Case #%d: %03d"%(i+1,ans))