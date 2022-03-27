N = int(input())
A = [*map(int, input().split())]
x = 0
for i in A:
    x ^= i
for i in A:
    if x ^ i == 0:
        print("Win")
        exit()
print("Win" if N & 1 else "Lose")
