N=int(input())

def f(x):
    return sum(int(i)**2 for i in str(x))

d={N:1}
while 1:
    N=f(N)
    if N==1: break
    if d.get(N):
        print("UNHAPPY")
        exit()
    d[N]=1

print("HAPPY")