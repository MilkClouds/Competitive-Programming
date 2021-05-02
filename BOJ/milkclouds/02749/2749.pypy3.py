N=int(input())
DP=[0,1,1,2]
import sys
if N<4:
	print(DP[N])
	sys.exit()
# 주기 1500000
N%=15*10**5

a=2
b=1
for i in range(N-3):
	a,b=(a+b,a)
	a%=1000000
print(a)