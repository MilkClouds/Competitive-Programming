from bisect import bisect_left as b
import sys
input=sys.stdin.readline
N=int(input())
A=list(map(int,input().split()))
DP=[];l=0
for i in range(N):
	pos=b(DP,A[i])
	if pos==l:
		DP.append(A[i]);l+=1
	else:
		DP[pos]=A[i]
print(l)