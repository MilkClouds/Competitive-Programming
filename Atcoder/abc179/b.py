N = int(input())
cnt = 0
for _ in range(N):
    a, b = map(int, input().split())
    if a == b:
        cnt += 1
    else:
        cnt = 0
    if cnt == 3:
        print("Yes")
        exit()
print("No")
