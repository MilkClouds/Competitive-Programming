import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=list(map(int,input().split()))

cur=0;last=0;ret=0
for i in range(n):
	curr=cur+a[i]
	if curr>m:
		while curr>m and last<n:
			curr-=a[last]
			last+=1
	if curr==m:
		ret+=1
	cur=curr
print(ret)