import sys;input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))
r=sum(a[:k])
ans=r
for i in range(n-k):
	r=r+a[k+i]-a[i]
	ans=max(ans,r)
print(ans)