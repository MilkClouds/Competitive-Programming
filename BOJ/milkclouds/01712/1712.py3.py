# a+b*x<c*x
# x>a/(c-b)
from math import *
a,b,c=map(int,input().split())
if b>=c:
    print(-1)
    exit()
print(int(a/(c-b))+1)