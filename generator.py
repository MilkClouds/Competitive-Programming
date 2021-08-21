from random import *
from math import *

def solve(L, R):
    ans = 0
    for i in range(L, R + 1):
        for j in range(L, R + 1):
            g = gcd(i, j)
            if g == 1 or i // g == 1 or j // g == 1: continue 
            ans += 1
    return ans

for i in range(10):
    L = randint(1, 10 ** 6 - 10)
    R = L + 10
    if i == 0:
        L = 1000
        R = L + 10
    with open('test/in/%d.txt' % (i + 1), 'w') as file:
        file.write("%d %d\n" % (L, R))
    with open('test/out/%d.txt' % (i + 1), 'w') as file:
        file.write("%d\n" % solve(L, R))
    
print(1)