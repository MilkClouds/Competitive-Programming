MI = lambda: map(int, input().split())
N, X = MI()
T = 0
for i in range(N):
    V, P = MI()
    T += V * P
    if T > X * 100:
        print(i + 1)
        exit()
print(-1)
