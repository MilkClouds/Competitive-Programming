t=list(map(int,input().split()))+list(map(int,input().split()))[::-1]
m=0;r=[]
for i in range(4):
	a=t[0]/t[3]+t[1]/t[2]
	if m<a: m=a;r=[i]
	elif m==a: r.append(i)
	t=[t[-1]]+t[:3]
print(min(r))