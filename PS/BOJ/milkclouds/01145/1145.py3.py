from math import *
lcm=lambda a,b:a*b//gcd(a,b)
a=[*map(int,input().split())]
from itertools import combinations

ans = 10**10
for i in combinations(a, 3):
    ans = min(ans, lcm(lcm(i[0],i[1]),i[2]))
print(ans)