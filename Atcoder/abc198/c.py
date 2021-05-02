R, X, Y = map(int, input().split())
A = (X ** 2 + Y ** 2) ** .5
if A < R:
    print(2)
else:
    print(int(A) // R + ((int(A) // R) * R < A))
