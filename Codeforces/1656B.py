import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [*map(int, input().split())]
    b = {}
    for i in a:
        b[i] = 1
    for i in a:
        if b.get(i - k):
            print("YES")
            break
    else:
        print("NO")