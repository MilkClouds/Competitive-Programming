import sys;input=sys.stdin.readline
n=int(input())
a=sorted([int(input())for i in range(n)])
ret=0;s=0
for i,j in enumerate(a):
	if j<=s: continue
	s+=1
	ret+=j-s
print(ret)