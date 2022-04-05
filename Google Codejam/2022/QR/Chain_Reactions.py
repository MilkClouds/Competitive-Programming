import sys
sys.setrecursionlimit(10 ** 7)
for tc in range(int(input())):
    N = int(input())
    F = [*map(int, input().split())]
    P = [*map(int, input().split())]
    adj = [[] for _ in range(N + 1)]
    vis = [0] * (1 + N)
    for i, p in enumerate(P):
        adj[p].append(i + 1)
    def dfs(u, par):
        global ans
        A = []
        for v in adj[u]:
            if v == par:
                continue
            A.append(dfs(v, u))
        A.sort()
        for i in range(1, len(A)):
            ans += A[i]
        if u == 0:
            return A[0]
        return max(F[u - 1], A[0]) if A else F[u - 1]
    ans = 0
    a = dfs(0, -1)
    ans += a
    print("Case #%d: %d" % (tc + 1, ans))