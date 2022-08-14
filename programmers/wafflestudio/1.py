A = [(1 << 1000) - 1] * 1000
def f(x):
    c = 0
    while x > 0:
        c += x & 1
        x >>= 1
    return c
try:
    while 1:
        cmd, x, _, y = input().split()
        a, b, c, d = map(int, (*x.split(","), *y.split(",")))
        mask = ((1 << d + 1) - 1) ^ ((1 << b) - 1)
        for i in range(a, c + 1):
            if cmd == 'front':
                A[i] |= mask
            elif cmd == 'back':
                A[i] &= ~mask
            else:
                A[i] ^= mask
except:
    pass
print(sum(map(f, A)))
