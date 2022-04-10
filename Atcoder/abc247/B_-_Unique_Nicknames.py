N = int(input())
chk = {}
A = []
for _ in range(N):
    a, b = input().split()
    A.append((a, b))
    chk[a] = chk.get(a, 0) + 1
    chk[b] = chk.get(b, 0) + 1
for i in range(N):
    a, b = A[i]
    chk[a] -= 1
    chk[b] -= 1
    if chk[a] and chk[b]:
        print("No")
        exit()
    chk[a] += 1
    chk[b] += 1
print("Yes")
