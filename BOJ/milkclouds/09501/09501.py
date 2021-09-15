for i in range(int(input())):
    A, B = map(int, input().split())
    N = int(B ** (1/3)) - int(A ** (1/3)) + (int(A ** (1/3)) ** 3 == A)
    print("Case #%d: %d" % (i + 1, N))
