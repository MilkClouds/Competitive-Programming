def gcd(a,b):
    while a%b!=0:
        a,b=b,a%b
    return b

a,b=map(int,input().split(":"))
g=gcd(a,b)
print("%d:%d"%(a//g,b//g))