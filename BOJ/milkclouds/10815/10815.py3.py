import sys
input=sys.stdin.readline
n=int(input())
arr=sorted(map(int,input().split()))
m=int(input())
for i in map(int,input().split()):
	start=0
	end=n-1
	while start<=end:
		mid=(start+end)//2
		if arr[mid]>i:
			end=mid-1
		else:
			start=mid+1
	print(1 if arr[end]==i else 0,end=' ')