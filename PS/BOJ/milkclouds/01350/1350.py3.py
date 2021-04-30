n=int(input())
a=list(map(int,input().split()))
cl=int(input())

ret=0
for i in a:
	if i%cl==0:ret+=i//cl
	else:ret+=i//cl+1
print(ret*cl)