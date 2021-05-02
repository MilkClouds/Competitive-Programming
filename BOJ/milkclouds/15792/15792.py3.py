A,B=map(int,input().split())
print(str(A//B)+'.',end='')
n,m=A%B,B
i=0
while i<2000:
	print(n*10//m,end='')
	n=n*10%m;i+=1