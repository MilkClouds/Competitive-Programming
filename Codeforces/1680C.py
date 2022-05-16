import sys
input = sys.stdin.readline
for _ in range(int(input())):
    S = input().rstrip()
    A = []
    for i, j in enumerate(S):
        if j == '1':
            A.append(i)
    N1 = len(A)
    ans = 10 ** 9
    for i in range(N1):
        # 0, N1 - 1
        # 1, N1 - 2
        # a_N - a_1 +1 -N, 0
        l, r = i - 1, N1 - 1
        while l + 1 < r:
            m = l + r + 1 >> 1
            if A[m] - A[i] + 1 - N1 >= 0:
                r = m
            else:
                l = m
        ans = min(ans, max(A[r] - A[i] + i - r, N1 - r + i - 1))
        if r > i:
            r -= 1
            ans = min(ans, max(A[r] - A[i] + i - r, N1 - r + i - 1))
    print(ans if N1 else 0)