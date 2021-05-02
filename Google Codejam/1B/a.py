T = int(input())
def valid(A, B, C, t):
    h, m, s, n = t
    if 0 <= h < 12 and 0 <= m < 60 and 0 <= s < 60 and 0 <= n < 10 ** 9:
        return 1
    return 0
def process(a):
    M = 36 * 10 ** 11
    h = a // M
    a %= M
    M //= 60

    m = a // M
    a %= M
    M //= 60

    s = a // M
    a %= M

    n = a
    return (h, m, s, n)

k1 = 36 * 10 ** 11
k2 = k1 // 60
k3 = k2 // 60

for i in range(T):
    A, B, C = map(int, input().split())
    print(A // k3, B // k3, C // k3)
