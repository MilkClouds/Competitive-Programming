X,Y=map(float,input().split())
n=int(input())
ans=X/Y*1000
for _ in range(n):
    a,b=map(float,input().split())
    ans=min(a/b*1000,ans)
print(ans)