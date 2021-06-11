import sys
input = sys.stdin.readline
N, M = map(int, input().split())
a = b = c = 0
for i in range(N):
    for j, x in enumerate(map(int, input().split())):
        if x == 1:
            if c:
                print(abs(a - i) + abs(b - j))
                exit()
            else:
                a = i
                b = j
                c = 1