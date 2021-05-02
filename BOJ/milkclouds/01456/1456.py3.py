def PrimeNumber(n):
    seive = [False, False, True, True] + [True] * (n-3)
    seive[4::2] = [False] * (n//2 - 1)
    k = 3
    while k <= int(n ** 0.5):
        if seive[k]:
            seive[k*2::k] = [False] * (n//k - 1)
        k += 2
    return [x for x in range(n+1) if seive[x]]
a,b = map(int, input().split())
plist = PrimeNumber(int(b ** 0.5))
count = 0
for p in plist:
    n = 2
    while True:
        k = p ** n
        if k > b:
            break
        elif k >= a:
            count += 1
        n += 1
print(count)