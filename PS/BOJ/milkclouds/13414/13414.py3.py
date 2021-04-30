import sys
input=sys.stdin.readline
n,m=map(int,input().split())
r={}
d=[];c=0
for i in range(m):
	num=int(input())
	r[num]=i
	d.append(num)
cur=0;rr=sorted(r.values());limit=len(rr)
for i in d:
	if cur==n or limit==cur:break
	if r[i]==rr[cur]:
		cur+=1
		print('%08d'%i)