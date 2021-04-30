n=int(input())
a=[]
for i in range(n):
	a.append(list(map(int,input().split())))
ans=a[n-1][0]*a[0][1]-a[0][0]*a[n-1][1]
for i in range(n-1):
	ans+=a[i][0]*a[i+1][1]
	ans-=a[i+1][0]*a[i][1]
print("%.1f"%(abs(ans)/2))