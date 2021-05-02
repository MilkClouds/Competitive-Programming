from bisect import bisect_left as b
import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
dp=[];l=0
for i in a:
	p=b(dp,i)
	if l==p:
		dp.append(i)
		l+=1
	else:
		dp[p]=i
print(n-l)