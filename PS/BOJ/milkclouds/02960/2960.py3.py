n,k=map(int,input().split())
arr=[1]*(n+1);rem=[]
for i in range(2,n+1):
	if not arr[i]: continue
	for e in range(i,n+1,i):
		if not arr[e]: continue
		arr[e]=0;rem.append(e)
print(rem[k-1])