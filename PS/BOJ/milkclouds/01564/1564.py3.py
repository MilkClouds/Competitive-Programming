N=int(input())
MOD=10**12
ret=1
for i in range(2,N+1):
	while(i%10==0):i//=10
	ret=ret*i
	while(ret%10==0):ret//=10
	ret%=MOD
print(str(ret)[-5:])