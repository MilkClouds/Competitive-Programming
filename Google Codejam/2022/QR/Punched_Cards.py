for tc in range(int(input())):
    print("Case #%d:" % (tc + 1))
    r, c = map(int, input().split())
    A = [['.' for _ in range(2 * c + 1)] for _ in range(2 * r + 1)]
    for i in range(2 * r + 1):
        for j in range(2 * c + 1):
            if i <= 1 and j <= 1: continue
            if i % 2:
                A[i][j] = '.' if j % 2 else '|'
            else:
                A[i][j] = '-' if j % 2 else '+'
        print(''.join(A[i]))