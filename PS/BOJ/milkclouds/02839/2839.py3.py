N=int(input())
# 5a+3b=N
# print(a+b)

m=10**10
for i in range(N//5+1):
    n=N-i*5
    if n%3==0: m=min(m,i+n//3)

if m==10**10: print(-1)
else:print(m)