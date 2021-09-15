MIL = lambda: [*map(int, input().split())]
f = lambda a: max(a) - min(a)
A = MIL()
B = MIL()

print(max(f(A[::2] + B[::2]), f(A[1::2] + B[1::2])) ** 2)
