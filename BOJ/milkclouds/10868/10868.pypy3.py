import sys
n, m = map(int, input().split())
min_d = {}
min_d[1] = [int(line) for _, line in zip(range(n), sys.stdin)]
i = 1
while i * 2 <= n:
    i *= 2
    min_d[i] = list(map(min, *2 * [iter(min_d[i // 2])]))

def trailing(s):
    for i in range(s.bit_length()):
        if s&1<<i: return i
    return 0

def d(a,b):
    x = trailing(a)
    x = x if x>0 else 1
    res = 1
    while res.bit_length()<x+1 and a + res <= b: res <<= 1
    return res >> 1


for _, line in zip(range(m), sys.stdin):
    a, b = map(int, line.split())
    a -= 1
    l = 10**10
    while a < b:
        q = d(a, b)
        l = min(l, min_d[q][a // q])
        a += q
    print(l)