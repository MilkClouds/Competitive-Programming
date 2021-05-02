N=int(input())
l=[int(i) for i in input().split(' ')]
#N=5
#l=[1,2,3,2,1]
DP=[[l[i]] for i in range(N)]
for i in range(N):
	for j in range(i):
		if l[i]<l[j]:
			DP[i]=max(DP[j]+[l[i]],DP[i],key=lambda x:len(x))
print(len(max(DP,key=lambda x:len(x))))