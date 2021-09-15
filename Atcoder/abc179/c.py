N = int(input())
arr = [0] * (N + 1)
pn = []
ans = 0

def eratos():
    for i in range(2, N + 1):
        if arr[i]: continue
        pn.append(i)
        for j in range(i, N + 1, i):
            arr[j] = i
def divisors(i):
    d = {}
    ans = 1
    while i > 1:
        d[arr[i]] = d.get(arr[i], 0) + 1
        i //= arr[i]
    for i in d:
        ans *= d[i] + 1
    return ans

eratos()

for C in range(1, N):
    ans += divisors(N - C)
print(ans)
