N, M = map(int, input().split())
A = [input() for _ in range(N)]
isMBTI = lambda f: f[0] in "EI" and f[1] in "NS" and f[2] in "FT" and f[3] in "PJ"
ans = 0
for i in range(N):
    for j in range(M - 3):
        ans += isMBTI(A[i][j:j+4])
        ans += isMBTI(A[i][j:j+4][::-1])
for i in range(N - 3):
    for j in range(M):
        ans += isMBTI(A[i][j]+A[i+1][j]+A[i+2][j]+A[i+3][j])
        ans += isMBTI((A[i][j]+A[i+1][j]+A[i+2][j]+A[i+3][j])[::-1])
for i in range(N - 3):
    for j in range(M - 3):
        s = A[i][j] + A[i + 1][j + 1] + A[i + 2][j + 2] + A[i + 3][j + 3]
        ans += isMBTI(s) + isMBTI(s[::-1])
for i in range(3, N):
    for j in range(M - 3):
        s = A[i][j] + A[i - 1][j + 1] + A[i - 2][j + 2] + A[i - 3][j + 3]
        ans += isMBTI(s) + isMBTI(s[::-1])
print(ans)