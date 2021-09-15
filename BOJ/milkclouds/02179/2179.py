import sys
input = sys.stdin.readline
N = int(input())
d = [{} for _ in range(101)]
S = [''] * N
for j in range(N):
    S[j] = input().rstrip()
    for i in range(len(S[j])):
        d[i][S[j][:i + 1]] = d[i].get(S[j][:i + 1], []) + [j]
for i in range(100, -1, -1):
    for k, v in d[i].items():
        if len(v) >= 2:
            for a in v:
                for b in v:
                    if S[a] == S[b]: continue
                    print(S[a])
                    print(S[b])
                    exit()