import sys;sys.setrecursionlimit(999999)

input()
A=list(map(int,input().split()))

if not A:
	print(0)
	exit()
if len(list(filter(lambda x:x>0,A)))==0:
	print(max(A))
	exit()

dp=[[None]*2 for _ in range(len(A))]
# dp[cur][u]=제거 여부가 u이고 cur까지 진행했을 때 cur 포함하는 연속합 최대값
# dp[cur][0]=max(dp[cur-1][0]+A[cur],0)
# dp[cur][1]=max(dp[cur-1][0],dp[cur-1][1]+A[cur],0)
def solution(cur):
	if cur==len(A):return
	dp[cur][0]=max(dp[cur-1][0]+A[cur],0)
	dp[cur][1]=max(dp[cur-1][0],dp[cur-1][1]+A[cur],0)
	solution(cur+1)
dp[0][0]=max(A[0],0)
dp[0][1]=0
solution(1)

print(max(max(i) for i in dp))