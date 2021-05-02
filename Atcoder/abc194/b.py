import sys
input = sys.stdin.readline

N = int(input())
ans = 10 ** 30
X = []
for _ in range(N):
    X.append([*map(int, input().split())])

for i in range(N):
    ans = min(ans, sum(X[i]))
for i in range(N):
    for j in range(N):
        if i == j: continue
        ans = min(ans, max(X[i][0], X[j][1]))
print(ans)
