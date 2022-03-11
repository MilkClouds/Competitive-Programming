A = [int(input()) for _ in range(10)]
B = []
for i in range(11):
    S = sum(A[:i])
    B.append((abs(100 - S), -S))
B.sort()
print(-B[0][1])