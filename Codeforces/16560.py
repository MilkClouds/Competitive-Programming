import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    print(a.index(min(a)) + 1, a.index(max(a)) + 1)