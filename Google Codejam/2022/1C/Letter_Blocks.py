import sys
input = sys.stdin.readline
def dfs(u):
    global ans
    if vis[u]:
        return
    vis[u] = 1
    ans += S[u]
    adj[u].sort(key = lambda s: S[s][0] != S[s][-1])
    for v in adj[u]:
        dfs(v)
for tc in range(int(input())):
    N = int(input())
    S = input().rstrip().split()
    adj = [[] for _ in range(N)]
    deg = [0] * N
    vis = [0] * N
    for i in range(N):
        for j in range(N):
            if i == j: continue
            if S[i][0] == S[j][-1] and S[i][-1] == S[j][0]:
                adj[j].append(i)
                adj[i].append(j)
                continue
            if S[i][0] == S[j][-1]:
                adj[j].append(i)
                deg[i] += 1
            if S[i][-1] == S[j][0]:
                adj[i].append(j)
                deg[j] += 1
    ans = ""
    for i in range(N):
        if deg[i] == 0:
            dfs(i)
    if len(ans) != len(''.join(S)):
        print("Case #%d: %s" % (tc + 1, "IMPOSSIBLE"))
        continue
    chk = {}; chk[ans[0]] = 1;
    for j in range(1, len(ans)):
        if ans[j - 1] == ans[j]:
            continue
        if chk.get(ans[j]):
            print("Case #%d: %s" % (tc + 1, "IMPOSSIBLE"))
            break
        chk[ans[j]] = 1
    else:
        print("Case #%d: %s" % (tc + 1, ans))
