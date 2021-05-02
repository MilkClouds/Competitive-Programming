import sys
input=sys.stdin.readline
n,m=map(int,input().split())
d=[0]*n
for i in range(m):
	a,b=map(lambda x:int(x)-1,input().split())
	d[a]+=1
	d[b]+=1
print(*d,sep='\n')