import sys
input = sys.stdin.readline
N, K = map(int, input().split())
if N == 1:
    print("0\n" * 11)
    exit()
t = pow(N, 10)
P = [{} for _ in range(11)]
for _ in range(K):
    A = tuple(map(int, input().split()))
    for i in range(11):
        S = A[:i] + A[i + 1:]
        if not P[i].get(S):
            P[i][S] = [0, N + 1]
        P[i][S].append(A[i])
for i in range(11):
    cnt = -len(P[i])
    for k, v in P[i].items():
        v.sort()
        for j in range(len(v) - 1):
            cnt += (v[j + 1] - v[j] >= 3)
    print(t + cnt)