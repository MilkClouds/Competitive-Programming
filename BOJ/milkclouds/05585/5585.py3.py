n=1000-int(input())
d=[500,100,50,10,5,1]
ret=0
for i in d:
	ret+=n//i
	n%=i
print(ret)