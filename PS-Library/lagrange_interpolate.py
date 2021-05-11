from functools import lru_cache

MOD = 998_244_353
MAX = 1002 # aware!
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

# 자세히 보면 라그랑주 보갼법의 기본적인 식과 똑같다!
# 잘 모르겠으면 그냥 쓰자!
# (0, F[0]), (1, F[1]), ... (n - 1, F[N - 1])을 지나는 함수에 대해 F(x)를 구하라고 한다.
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

# Time Complexity: O(1) for already known n, otherwise O(len(F))
def lagrange(F, n):
    if n < len(F):
        return F[n]
    return interpolate(F, n)


# 주어진 F에 대해 n=2일 때 O(1) 메서드인 lagrange 쓰지 않고도 답이 나오긴 한다! O(len(F))가 걸릴 뿐이지..
F = [0, 1, 2, 3, 4]
print(interpolate(F, 2))