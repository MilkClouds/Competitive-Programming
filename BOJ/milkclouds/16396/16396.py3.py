import sys
input=sys.stdin.readline

n=int(input())
a=[]
for _ in range(n):
    x,y=map(int,input().split())
    if x>y:x,y=y,x
    a.append((x,1))
    a.append((y,0))
a.sort()
ans=stack=last=0
for i in a:
    x,y=i
    if stack:
        ans+=x-last
        last=x
    if y==0:
        ans+=x-last
        stack-=1
    else:
        stack+=1
    if stack:
        last=x
print(ans)