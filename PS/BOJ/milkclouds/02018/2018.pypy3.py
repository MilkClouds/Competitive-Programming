N=int(input())

def f(x):
    return x*x+(2*a-1)*x-N*2
def g(x):
    return 2*x+2*a-1
def D():
    return (2*a-1)**2+4*N*2
def ans():
    return (1-2*a+D()**.5)/2

def solve():
    t=ans()
    return t==int(t)

ret=0
for a in range(1,N+1):
    if D()<0:
        continue
    ret+=solve()
print(ret)
