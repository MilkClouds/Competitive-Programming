n=int(input())
t=1;ret=0;r=1
while t<=n:
	ret+=r*(t*9)
	t*=10;r+=1
ret-=(t-n-1)*(r-1)
print(ret)