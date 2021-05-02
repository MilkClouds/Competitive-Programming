import sys
input=sys.stdin.readline
n=int(input())
a=sorted(map(int,input().split()))
diction={}
for i in a:
    diction[i]=True

ans=2
for i in range(n):
    for j in range(i):
        if n-i+1<ans: continue
        diff=a[i]-a[j]
        ret=2;cur=a[i]
        while diction.get(cur+diff):
            ret+=1
            cur+=diff
        ans=max(ans,ret)

print(ans)