import sys, bisect
input = sys.stdin.readline
INF = 10 ** 9
def f(S):
    for i, j in enumerate(S[::-1]):
        if j == '*':
            return len(S) - i
    return 0
for _ in range(int(input())):
    N = int(input())
    S1 = input().rstrip()
    S2 = input().rstrip()
    N = max(f(S1), f(S2))
    dp = [[INF] * 2 for _ in range(N)]
    if S1[0] == '*' or S2[0] == '*':
        dp[0] = [int(S2[0] == '*'), int(S1[0] == '*')]
    for i in range(N - 1):
        if dp[i][0] != INF:
            if S2[i + 1] == '.':
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1)
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 2)
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2)
        if dp[i][1] != INF:
            if S1[i + 1] == '.':
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1)
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 2)
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2)
        if dp[i][0] == INF and dp[i][1] == INF and (S1[i + 1] == '*' or S2[i + 1] == '*'):
            dp[i + 1] = [int(S2[i + 1] == '*'), int(S1[i + 1] == '*')]
    print(min(dp[N - 1]))