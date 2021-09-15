N, X, M = map(int, input().split())
Y = X
ans = 0
D = []
vis = [0] * M
cnt = 1

while not vis[Y]:
    vis[Y] = cnt
    cnt += 1
    D.append(Y)
    ans += Y
    Y = (Y ** 2) % M

cnt = vis[Y]
cL = len(D) - cnt + 1

vis = [0] * M
while not vis[Y]:
    vis[Y] = cnt
    ans += ((N - cnt) // cL) * Y
    cnt += 1
    Y = (Y ** 2) % M


print(ans)
