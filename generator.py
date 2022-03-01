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
    N = 10 ** 4
    Q = 10 ** 5
    Qs = []
    for i in range(Q):
        A, B = randint(2, N - 1), randint(0, 10 ** 9 + 7 - 1)
        Qs.append((A, B))
    with open('test/in/%d.txt' % (i + 1), 'w') as file:
        file.write("%d %d\n" % (N, Q))
        for i in range(Q):
            file.write("%d %d\n" % Qs[i])
    # with open('test/out/%d.txt' % (i + 1), 'w') as file:
        # file.write("%d\n" % solve(L, R))
    
print(1)