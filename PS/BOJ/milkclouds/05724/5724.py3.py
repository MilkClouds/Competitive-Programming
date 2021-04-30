def solve(n):
    return n*(n+1)*(2*n+1)//6

import sys
for n in map(int,sys.stdin):
    if n:
        print(solve(n))