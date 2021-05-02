import sys
input=sys.stdin.readline
n=int(input())
a=input()[:-1];b=a[::-1]
lcs=[[0]*(n+1) for i in range(n+1)]
for i in range(1,n+1):
	for j in range(1,n+1):
		if a[i-1]==b[j-1]:
			lcs[i][j]=lcs[i-1][j-1]+1
		else:
			lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])
print(n-lcs[n][n])