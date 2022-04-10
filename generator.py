from random import *
from math import *

# def solve(L, R):
#     ans = 0
#     for i in range(L, R + 1):
#         for j in range(L, R + 1):
#             g = gcd(i, j)
#             if g == 1 or i // g == 1 or j // g == 1: continue 
#             ans += 1
#     return ans

for i in range(1):
    N = 1 * 10 ** 4
    Qs = []
    for i in range(N):
        A, B, C = randint(1, 150), randint(1, 150), randint(1, 10 ** 9)
        Qs.append((A, B, C))
    with open('test/in/%d.txt' % (i + 1), 'w') as file:
        file.write("%d\n" % (N))
        for i in range(N):
            file.write("%d %d %d\n" % Qs[i])
    # with open('test/out/%d.txt' % (i + 1), 'w') as file:
        # file.write("%d\n" % solve(L, R))
    
print(1)