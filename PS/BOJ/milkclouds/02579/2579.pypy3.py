N=int(input())

sc=[]
for i in range(N):
	sc.append(int(input()))
if N==1:
	print(sc[0])
	import sys
	sys.exit()
DP=[[0,0] for i in range(N)]

DP[0][0]=sc[0]
DP[1][0]=sc[1]
DP[1][1]=sc[0]+sc[1]

for i in range(2,N):
	DP[i][0]=max(DP[i-2])+sc[i]
	DP[i][1]=DP[i-1][0]+sc[i]
print(max(DP[N-1]))
