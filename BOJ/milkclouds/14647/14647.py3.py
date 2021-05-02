import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=[0]*501
b=[0]*501
tot=0
for i in range(n):
	for j,d in enumerate(input().split()):
		c=d.count('9')
		a[i]+=c
		b[j]+=c
		tot+=c
print(tot-max(max(a),max(b)))