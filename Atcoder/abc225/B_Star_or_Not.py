N = int(input())
I = [0] * (N + 1)
for i in range(N - 1):
    u, v = map(int, input().split())
    I[u] += 1
    I[v] += 1
for i in range(N):
    if I[i + 1] == N - 1:
        print("Yes")
        exit()
print("No")