a,b=map(int,input().split())
if a<b:a,b=b,a

ans=''
while a and b:
    ans=str(a%10+b%10)+ans
    a//=10
    b//=10
if a:
    ans=str(a)+ans
print(ans)