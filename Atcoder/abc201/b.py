N = int(input())
A = []
for _ in range(N):
    x, y = input().split()
    A.append((int(y), x))
A.sort(rev = 1)
print(A[1][1])