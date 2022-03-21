ans = 0
f = -1
for _ in range(int(input())):
    N = int(input())
    if ~f:
        ans += N - f
        f = -1
    else:
        f = N
print("still running" if ~f else ans)