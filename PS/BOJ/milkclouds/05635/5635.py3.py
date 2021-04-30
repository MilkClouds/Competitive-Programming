n=int(input())
a=[]
for i in range(n):
	i,*t=input().split()
	j,x,y=map(int,t)
	a.append((y*366+x*31+j,i))
a.sort()
print(a[-1][1])
print(a[0][1])