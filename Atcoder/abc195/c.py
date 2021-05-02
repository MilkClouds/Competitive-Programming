N = int(input())

c = 0
l = 1
r = 1000
ans = 0
while r <= N:
    ans += c * (r - l)
    c += 1
    l *= 1000
    r *= 1000

ans += (N - l + 1) * c
print(ans)
