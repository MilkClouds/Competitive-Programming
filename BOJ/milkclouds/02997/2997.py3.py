a,b,c=sorted(map(int,input().split()))
if(2*b==a+c):print(2*c-b)
else:
	if((b-a)*2+b==c):print(2*b-a)
	else:print(c-b+a)