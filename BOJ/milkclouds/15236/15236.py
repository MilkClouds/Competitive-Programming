N = int(input())
ans = 0
for i in range(1, 1 + N):
    ans += i * (1 + i) + (i + 1) * i // 2
print(ans)
