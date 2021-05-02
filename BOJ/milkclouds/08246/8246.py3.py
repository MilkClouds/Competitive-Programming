a,b,k = map(int, input().split())
if a<b: a,b=b,a
if a // k == 0 or b // k == 0: print(0)
elif b // k == 1: print(a//k)
else: print(max(0, (b // k - 2 + a // k) * 2))