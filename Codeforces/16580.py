import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    S = input()
    c = 0
    p = 0
    ans = 0
    for i in range(n):
        if S[i] == '0':
            if p == 1:
                ans += max(0, 2 - c)
            p = 1
            c = 0
        else:
            c += 1
    print(ans)