import sys
input = sys.stdin.readline
H, W = map(int, input().split())
A = [[*input().rstrip()] for _ in range(H)]
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
p = lambda x, y: 0 <= x and x < H and 0 <= y and y < W
for i in range(H):
    for j in range(W):
        if A[i][j] != '.': continue
        S = {'1', '2', '3', '4', '5'}
        for dx, dy in d:
            x = i + dx
            y = j + dy
            if p(x, y):
                S.discard(A[x][y])
        A[i][j] = S.pop()
[print(''.join(A[i])) for i in range(H)]