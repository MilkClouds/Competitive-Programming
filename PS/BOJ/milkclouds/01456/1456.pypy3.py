import math

n,m=map(int,input().split())

mm=int(m**.5)
arr=[0]*(mm+1)
pn=[2]
for i in range(3,mm+1,2):
	if arr[i]: continue
	pn.append(i)
	for j in range(i*i,mm+1,i*2):
		arr[j]=1
cnt=0
for i in pn:
	t=math.log(n,i)
	if t>=2:
		t=int(t)-1 if i**int(t)==n else int(t)
	else:
		t=1
	cn=int(math.log(m,i))-t
	cnt+=cn
print(cnt)