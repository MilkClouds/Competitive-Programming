N = int(input())
if N==0: print("NO");exit()
fac={}
def fact(X):
    if fac.get(X): return fac[X]
    if X==0: return 1
    else:
        fac[X]=X*fact(X-1)
        return fac[X]
for i in range(25, -1, -1):
    if N>=fact(i): N-= fact(i)
if N==0: print ("YES")
else: print("NO")