A, B = 1, 0
N = int(input())
for i in range(N - 1):
    A, B = A + B, A + B - (i % 2)
print(B)