N = int(input())
D = []
for i in range(N):
    a, b = input().split()
    b = int(b)
    D.append((b, a))

D.sort()
print(D[0][1])