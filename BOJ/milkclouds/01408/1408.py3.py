a=input()
b=input()

d=[1,60,3600][::-1]
x=sum([d[i]*j for i,j in enumerate(map(int,a.split(':')))])

y=sum([d[i]*j for i,j in enumerate(map(int,b.split(':')))])+24*3600

t=(y-x)%(24*3600)
ret=[]
for i in d:
	ret.append(t//i)
	t%=i
print('%02d:%02d:%02d'%tuple(ret))