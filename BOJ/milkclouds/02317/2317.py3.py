from bisect import *
import sys
input=sys.stdin.readline

n,k=map(int,input().split())
a=[int(input())for _ in range(k)]
ret=0
for i in range(k-1):
	ret+=abs(a[i]-a[i+1])
m=min(a)
M=max(a)
b=[*filter(lambda x:not (m<=x<=M),[int(input())for _ in range(n-k)])]


mm=min(b)
MM=max(b)

if k==0:
	ret=MM-mm
elif n!=k:
	if mm<m:
		ret+=min((m-mm)*(1 if a[0]==m or a[k-1]==m else 2),a[0]-mm,a[k-1]-mm)
	if MM>M:
		ret+=min((MM-M)*(1 if a[0]==M or a[k-1]==M else 2),MM-a[0],MM-a[k-1])
print(ret)