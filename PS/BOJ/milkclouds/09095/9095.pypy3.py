DP=[1,2,4,7]+[0 for i in range(7)]
dp=4
for i in range(int(input())):
	r=int(input())
	for i in range(dp,r):
		DP[i]=DP[i-1]+DP[i-2]+DP[i-3]
		dp=i
	print(DP[r-1])