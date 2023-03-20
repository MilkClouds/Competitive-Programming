MOD = 10 ** 9 + 7
inv = lambda x: pow(x, MOD - 2, MOD)
N, M = map(int, input().split())

a0 = 24 * (N - 2) * inv(4 * (N - 1)) % MOD
r = (12 * N - 16) * inv(4 * (N - 1)) % MOD
S = a0 * (pow(r, M, MOD) - 1) * inv(r - 1) + 6

print(pow(12 * N - 16, M, MOD), S * pow(4 * (N - 1), M, MOD) % MOD)