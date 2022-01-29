N = int(input())
A = [*map(int, input().split())]
M = int(input())
f = lambda A, M: pow(A[-1], f(A[:-1], M - 1), M) if len(A) > 1 else A[0]
print(f(A, M) % M if A[-1] % M else 0)