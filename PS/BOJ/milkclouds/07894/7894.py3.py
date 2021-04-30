from math import *
def f(n):
    t = n*(log(n)-1) + 1/2*log(2*pi*n)
    return int(t / log(10))

for _ in range(int(input())):
    n = int(input())
    if n < 100:
        print(int(log10(factorial(n)))+1)
    else:
        print(int(f(n))+1)