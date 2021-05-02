n=int(input())
from itertools import permutations as p
for d,e,h,l,o,r,w in p(range(0,10),7):
    if h==0 or w==0:continue
    a=h*10000+e*1000+l*110+o
    b=w*10000+o*1000+r*100+l*10+d
    if a+b!=n:continue
    print("  %d\n+ %d\n-------\n%7d"%(a,b,n))
    exit()
print("No Answer")