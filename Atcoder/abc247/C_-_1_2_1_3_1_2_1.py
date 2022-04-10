def f(N):
    if N == 1:
        return '1'
    S = f(N - 1)
    return "%s %d %s" % (S, N ,S)
print(f(int(input())))