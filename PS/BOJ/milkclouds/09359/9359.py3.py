import sys;input=sys.stdin.readline
M=int(1e9**.5)+1
arr=[True]*M
pn=[2]
for i in range(3,M,2):
	if arr[i]:
		pn.append(i)
		for j in range(i*i,M,i*2):
			arr[j]=False
for idx in range(1,1+int(input())):
	A,B,N=map(int,input().split())
	fac=[]
	for i in pn:
		N%i or fac.append(i)
		while N%i==0:
			N//=i
	if N>1: fac.append(N)
	size=1<<len(fac);ans=0
	for i in range(1,size):
		cnt=0;num=1
		for p in range(len(fac)):
			if i&(1<<p):
				num*=fac[p]
				cnt+=1
		lo=(A//num)-(A%num==0)
		hi=B//num
		cc=hi-lo
		ans+=cc if cnt&1 else -cc
	print('Case #%d:'%idx,B-A+1-ans)