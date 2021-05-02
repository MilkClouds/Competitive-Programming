N, M = map(int, input().split())
d = {}
revd = {}
for _ in range(N):
    S = input()
    d[S] = []
    T = int(input())
    for _ in range(T):
        x = input()
        d[S].append(x)
        revd[x] = S
    d[S].sort()

for _ in range(M):
    S = input()
    if int(input()):
        print(revd[S])
    else:
        print(*d[S], sep = '\n')
