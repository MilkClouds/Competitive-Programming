import sys
input = sys.stdin.readline
for tc in range(int(input())):
    N = int(input())
    A = sorted(map(int, input().split()))
    ans = 0
    for i in range(N):
        if ans + 1 <= A[i]:
            ans += 1
    print("Case #%d: %d" % (tc + 1, ans))