MI = lambda: map(int, input().split())
N, M = MI()
last = -1
bias = -1
B = list(MI())
last = B[0]
if ((B[0] - 1) // 7 != (B[M - 1] - 1) // 7) or [*range(last, last + M)] != B:
    print("No")
    exit()
for i in range(N - 1):
    B = list(MI())
    S = last + (i + 1) * 7
    if [*range(S, S + M)] != B:
        print("No")
        exit()
print("Yes")