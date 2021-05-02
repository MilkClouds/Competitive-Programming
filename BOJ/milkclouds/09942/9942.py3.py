'''
T(n,r) : 원반 n개, 디스크 r개

1. T(k,r)
2. T(n-k,r-1)
3. T(k,r)
'''
import sys

def closeint(i):
	if abs(i-int(i))>0.5:
		return int(i)+1 if i>0 else int(i)-1
	return int(i)

dp=[[0]*5 for _ in range(10005)]
def T(n,r):
	if n==1: return 1
	if r==3:
		return 2**n-1
	if dp[n][r]: return dp[n][r]
	m=10**50
	# for k in range(1,n):
	k=n-closeint((2*n+1)**.5)+1 # 4-peg 문제에서 최적의 k는 이와 같다.
	m=min(m,2*T(k,r)+T(n-k,r-1))
	dp[n][r]=m
	return m

for idx,i in enumerate(map(int,sys.stdin)):
	print("Case %d: %d"%(idx+1,T(i,4)))