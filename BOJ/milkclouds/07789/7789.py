while 1:
    l = input()
    if l == '0': break
    N, P = map(int, l.split())
    if N // 2 < P:
        if P % 2:
            print(N - P, N - P + 1, P + 1)
        else:
            print(N - P + 1, N - P + 2, P - 1)
    else:
        if P % 2:
            print(P + 1, N - P, N - P + 1)
        else:
            print(P - 1, N - P + 1, N - P + 2)
