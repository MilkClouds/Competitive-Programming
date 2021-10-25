N, S, T, A, B = map(int, input().split())
from fractions import *
f = Fraction
def sqrt(x):
    j = 0
    for i in range(30, -1, -1):
        if (j + (1 << i)) ** 2 <= x:
            j += 1 << i
    return j
    
a = (2 * T + 1 - sqrt(f(8 * N * B) / f(A) + 1))
a = max(1, (a + 1) >> 1)
if S < a or S > T:
    print("%.16lf" % (float(N) * B / (T - a + 1) + (float(T) - a) / 2 * A))
else:
    print((T - S) * A)