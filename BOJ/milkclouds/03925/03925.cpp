import sys
N = int(input())
inp = [*map(lambda x: int(x, 16), ' '.join(sys.stdin).split())]
for i in range(N):
    A = inp[i * 9: (i + 1) * 9]
    key = 0
    for j in range(32):
        if (1 << j) & sum(A[:8]) != (1 << j) & A[8]:
            key |= 1 << j
            for k in range(8):
                A[k] ^= 1 << j
    print(hex(key)[2:])

