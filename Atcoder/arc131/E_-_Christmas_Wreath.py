import sys
print = lambda i: sys.stdout.write(i)
N = int(input())
if N <= 4 or N % 3 == 2:
    print("No")
    exit()
def divide(N):
    if N == 6:
        return [[1, 4], [2, 3], [5,]]
    if N == 7:
        return [[1, 6], [2, 5], [3, 4]]
    if N == 9:
        return [[1, 3, 8], [2, 4, 6], [5, 7]]
    if N == 10:
        return [[1, 5, 9], [2, 6, 7], [3, 4, 8]]
    a, b, c = divide(N - 6)
    return [a + [N - 1, N - 6], b + [N - 2, N - 5], c + [N - 3, N - 4]]
A = divide(N)
ans = [0] * N
for i in range(3):
    for j in A[i]:
        ans[N - j - 1] = 'RBW'[i]
print("Yes\n")
[print(ans[i] * (N - i - 1) + '\n') for i in range(N - 1)]