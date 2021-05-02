n = int(input())

a = n // 5
b = a - 1
ans = 10**9

if a>=0 and (n - 5*a) >=0 and (n-5*a)%2 == 0:
    ans = min(ans, a + (n-5*a)//2)
if b>=0 and (n-5*b)>=0 and (n-5*b)%2 == 0:
    ans = min(ans, b + (n-5*b)//2)

if ans == 10**9:
    print(-1)
else:
    print(ans)