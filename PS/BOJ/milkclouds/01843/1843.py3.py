n=int(input())

#1
l=(n-1)//2
s=l*(l+1)-(l if n&1 else 0)
print(s)


#2
a=[1]
for i in range(2,n//2+1):
	if n%i==0: a.append(i)
a.append(n)
arr=[0]*(n+1)
ret=0
for i in a:
	arr[i]=1
for i in range(len(a)):
	ii=a[i]
	for j in range(i,len(a)):
		jj=a[j]
		if ii+jj>n: continue
		if arr[ii+jj]:ret+=1
print(ret)


#3
arr=[1]*(n+1);pn=[2]
for i in range(3,n+1,2):
	if not arr[i]:continue
	pn.append(i)
	for e in range(i*i,n+1,i*2):
		arr[e]=0
arr=[0]*(n+1)
if n<2: print(0);exit()
for i in pn:
	arr[i]=1
s=0
for ii in range(1):
	i=pn[ii]
	for ee in range(ii,len(pn)):
		e=pn[ee]
		if i+e>n: continue
		if arr[i+e]:s+=1
print(s)