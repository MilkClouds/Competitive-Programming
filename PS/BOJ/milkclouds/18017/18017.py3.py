from decimal import *
d=Decimal
c=299792458
a,b=map(d,input().split())
print(min(c,(a+b)/(1+a*b/c/c)))