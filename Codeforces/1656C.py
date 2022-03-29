import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    S = set(a)
    if S & set((1,)):
        for i in S:
            if S & set((i - 1, i + 1)):
                print("NO")
                break
        else:
            print("YES")
    else:
        print("YES")