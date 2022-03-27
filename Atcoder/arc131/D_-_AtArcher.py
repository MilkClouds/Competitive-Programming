import sys, bisect
input = sys.stdin.readline
N, M, D = map(int, input().split())
r = [*map(int, input().split())][1:]
s = [*map(int, input().split())]
for i in range(M - 1):
    s[i] -= s[i + 1]
def f(n):
    ret = [0] * (D + 1)
    for i in range(M):
        ret[0] += s[i] * min(n, (r[i] // D + 1))
        if r[i] < n * D:
            ret[r[i] % D + 1] -= s[i]
    for i in range(D):
        ret[i + 1] += ret[i]
    return ret
a, b = f(N + 1 >> 1), f(N >> 1)
ret = 0
for i in range(D):
    ret = max(ret, a[i] + b[D - i])
print(ret)
