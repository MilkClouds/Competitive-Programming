from math import *

N, X, M = map(int, input().split())
Y = 1
ans = 0
pn = []

if gcd(X, M) != 1:
    Y = X
    while Y % M:
        Y = (Y ** 2) % M

def eratos():
    arr = [0] * (M + 1)
    for i in range(2, M + 1):
        if arr[i]: continue
        pn.append(i)
        for j in range(i, M + 1, i):
            arr[j] = i
def phi(x):
    ans = 1
    for p in pn:
        if x % p: continue
        k = 0
        while x % p == 0:
            x //= p
            k += 1
        ans *= pow(p, k) - pow(p, k - 1)
    return ans

eratos()
P = phi(M)
D = []
vis = [0] * P

for i in range(N):
    if vis[Y]: break
    vis[Y] = 1
    D.append(Y)
    Y = (Y * 2) % P
print(D)
for i in range(len(D)):
    ans += pow(X, D[i], M) * (1 + (N - i - 1) // len(D))

print(ans)
