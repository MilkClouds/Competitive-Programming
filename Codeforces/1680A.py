import sys
input = sys.stdin.readline
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    if a > c:
        a, b, c, d = c, d, a, b
    if b >= c:
        print(max(a, c))
    else:
        print(a + c)