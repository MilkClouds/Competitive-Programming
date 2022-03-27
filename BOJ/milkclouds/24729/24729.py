input()
B = [0] * (10 ** 5 + 1)
m = 10 ** 5
M = 0
for i in map(int, input().split()):
    B[i] += 1
    m = min(m, i)
    M = max(M, i)
if m == M:
    print(-1)
    exit()
for i in range(m, M):
    B[i + 1] -= B[i]
    if i + 1 == M:
        if B[i + 1]:
            print(-1)
            exit()
    elif B[i + 1] < 1:
        print(-1)
        exit()
print(1)