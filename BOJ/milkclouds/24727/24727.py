N = int(input())
A, B = map(int, input().split())
ans = [[0] * N for _ in range(N)]
X = [0, 0]
t = 0
for i in range(A):
    ans[X[0]][X[1]] = 1
    X[0] -= 1
    X[1] += 1
    if X[0] < 0 or X[1] >= N:
        t += 1
        X = [min(t, N - 1), 0 if t < N else t - N + 1]
X = [0, 0]
t = 0
for i in range(B):
    ans[N - 1 - X[0]][N - 1 - X[1]] = 2
    X[0] -= 1
    X[1] += 1
    if X[0] < 0 or X[1] >= N:
        t += 1
        X = [min(t, N - 1), 0 if t < N else t - N + 1]
d = ((0, 1), (0, -1), (1, 0), (-1, 0))
chk = 0
for i in range(N):
    for j in range(N):
        for dx, dy in d:
            x = i + dx
            y = j + dy
            if 0 <= x < N and 0 <= y < N:
                chk |= ans[i][j] == 1 and ans[x][y] == 2
                chk |= ans[i][j] == 2 and ans[x][y] == 1
if not chk and sum(ans[i].count(1) for i in range(N)) == A and sum(ans[i].count(2) for i in range(N)) == B:
    print("1")
    [print(*ans[i], sep = '') for i in range(N)]
else:
    print('-1')
