n=int(input())

t=1
s=0
while s<n:
	s+=t
	t+=1

a=t
b=s-n+1
print(b,a-b)