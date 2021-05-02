n=int(input())
r=0
while n>0:
    t=int((n*2)**.5)
    if t*(t+1)//2 > n:
        t-=1
    r+=t
    n-=t*(t+1)//2

print(r)
