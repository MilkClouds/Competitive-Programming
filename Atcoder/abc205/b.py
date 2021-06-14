N = int(input())
A = set(map(int, input().split()))
if A == set(range(1, N + 1)):
    print("Yes")
else:
    print("No")