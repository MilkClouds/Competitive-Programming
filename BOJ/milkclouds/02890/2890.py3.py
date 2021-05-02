import sys
input=sys.stdin.readline

R,C=map(int,input().split())

A=[None]*9
for _ in range(R):
	x=input()
	targetNumber=0
	for idx,i in enumerate(x):
		if i.isdigit():
			targetNumber=i
			break
	if not targetNumber: continue
	A[int(targetNumber)-1]=idx

r=sorted(set(A),reverse=1)
B={}
for i,j in enumerate(r):
	B[j]=i+1

for i in A:
	print(B[i])




