import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    c = [*map(int, input().split())]
    if c.count(1) != 1:
        print("NO")
        continue
    if n == 1:
        print("YES")
        continue
    s = c.index(1)
    if c[s] + 1 != c[(s + 1) % n]:
        print("NO")
        continue
    flag = 1
    for j in range(n):
        i = (s + j) % n
        nxt = (i + 1) % n
        flag &= c[i] == c[nxt] - 1 or c[i] >= c[nxt]
    print("YES" if flag else "NO")