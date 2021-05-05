N = int(input())
from math import *
a = ceil(N ** .5)
b = ceil(N / a)
print(max(4, (a + b - 2) << 1))