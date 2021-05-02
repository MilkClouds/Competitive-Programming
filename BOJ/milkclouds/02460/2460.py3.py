m=0;num=0
for i in range(10):
	a,b=map(int,input().split())
	num+=b-a
	num=num if num<10000 else 10000
	if m<num: m=num
print(m)