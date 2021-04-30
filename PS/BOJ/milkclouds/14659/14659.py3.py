import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
mmm=0;i=0
while i<n-1:
	mm=0
	for j in range(i+1,n):
		if a[i]>a[j]:
			mm+=1
		else: break
	i=j
	mmm=max(mm,mmm)
print(mmm)