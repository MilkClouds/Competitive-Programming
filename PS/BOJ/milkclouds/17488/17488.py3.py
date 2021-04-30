N, M = map(int, input().split())
L = [*map(int, input().split())]
A = [[] for i in range(M)]
B = [[] for i in range(M)]
ans = [[] for i in range(N)]

for i in range(N):
    C = [*map(int, input().split())][:-1]
    for j in C:
        A[j - 1].append(i)

for i in range(M):
    if L[i] >= len(A[i]):
        for j in A[i]:
            ans[j].append(i + 1)

for i in range(N):
    C = [*map(int, input().split())][:-1]
    for j in C:
        B[j - 1].append(i)

for i in range(M):
    if L[i] < len(A[i]) + len(B[i]): continue
    for j in B[i]:
        ans[j].append(i + 1)

for i in range(N):
    if ans[i]:
        print(*sorted(ans[i]))
    else:
        print("망했어요")
