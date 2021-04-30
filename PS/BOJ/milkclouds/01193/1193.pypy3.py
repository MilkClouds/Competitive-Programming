N=int(input())

index=1; tot=1
while tot<N:
	index+=1; tot+=index

# index 2배수, 1/y, 1+y=index+1
a=N-tot+index
b=index+1-a
if index%2==1:
	a,b=b,a
print(a,b,sep='/')
	