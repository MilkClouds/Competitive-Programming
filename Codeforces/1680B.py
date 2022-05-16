import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n, m = map(int, input().split())
    S = [input() for _ in range(n)]
    R = []
    for i in range(n):
        for j in range(m):
            if S[i][j] == 'R':
                R.append((i, j))
    if not R:
        print("YES")
        continue
    X = min(R)
    for Y in R:
        if not (X[0] <= Y[0] and X[1] <= Y[1]):
            print("NO")
            break
    else:
        print("YES")