import sys
input=sys.stdin.readline

n,m=map(int,input().split())
tree=list(map(int,input().split()))

start=1
end=max(tree)
while start<=end:
	mid=(start+end)//2
	ret=0
	for i in tree:
		ret+=max(i-mid,0)
	if m>ret:
		end=mid-1
	else:
		start=mid+1
print(end)