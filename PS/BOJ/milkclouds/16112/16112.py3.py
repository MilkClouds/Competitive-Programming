n,k=map(int,input().split())
A=sorted(map(int,input().split()))
tot=0;add=0
for i in range(n-1,-1,-1):
	if i<k: tot+=add
	add+=A[i]
print(tot)