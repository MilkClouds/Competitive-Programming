a=int(input())
b=int(input())
mod=int(1e9+7)

ret=1
while b:
	if b&1:ret=ret*a%mod
	b//=2
	a=a*a%mod
print(ret)