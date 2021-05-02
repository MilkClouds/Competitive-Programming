m,n=int(input()),int(input())
mi=10**10;sum=0
for i in range(int(m**0.5),int(n**0.5)+1):
	if m<=i**2<=n: sum+=i**2;mi=min(mi,i**2)
if sum==0: print(-1)
else:
	print(sum)
	print(mi)