from math import *

f = factorial
C = lambda n, r: f(n) // f(r) // f(n - r)
N = int(input()) - 1
if N < 3: print(0)
else: print(C(N, 3))