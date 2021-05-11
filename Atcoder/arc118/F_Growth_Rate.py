from functools import lru_cache

MOD = 998_244_353
MAX = 1002
fact = [1] * MAX
fact_inv = [1] * MAX
for n in range(1, MAX):
    fact[n] = fact[n - 1] * n % MOD

fact_inv[-1] = pow(fact[-1], MOD-2, MOD)
for n in range(MAX - 1, 0, -1):
    fact_inv[n - 1] = fact_inv[n] * n % MOD


@lru_cache(None)
def interpolate_denom(N):
    den = [1] * N
    for i in range(N):
        den[i] = fact_inv[N - 1 - i] * fact_inv[i] % MOD
        if i & 1:
            den[i] = -den[i]
    return den[::-1]
  
def interpolate(F, x):
    x %= MOD
    N = len(F)
    den = interpolate_denom(N)
    L = [1] * N
    for n in range(1, N):
        L[n] = L[n - 1] * (x - n + 1) % MOD
    R = 1
    res = 0
    for n in range(N - 1, -1, -1):
        res += R * L[n] % MOD * den[n] % MOD * F[n] % MOD
        R = R * (x - n) % MOD
    return res % MOD

def lagrange(F, n):
    if n < len(F):
        return F[n]
    return interpolate(F, n)

N, M = map(int, input().split())
A = [*map(int, input().split())]
f = [0, 1]
R = M
for a in A[::-1]:
    total = lagrange(f, R)
    n = len(f)
    g = [0] * (n + 1)
    for i in range(1, n + 1):
        g[i] = total - lagrange(f, a * i - 1)
        if g[i] < 0: g[i] += MOD
    f = g
    for i in range(1, len(f)):
        f[i] += f[i - 1]
        if f[i] >= MOD: f[i] -= MOD
    R = R // a

print(lagrange(f, R))