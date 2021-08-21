N = int(input())
ans = 0
for i in range(1000):
    if 1 << i <= N:
        ans = i
    else:
        break
print(ans)