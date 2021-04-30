people=[list(range(1,15))]+[[0]*14 for i in range(14)]

for i in range(1,15):
	for j in range(14):
		people[i][j]=sum(people[i-1][:j+1])

N=int(input())
for i in range(N):
	k,n=[int(input()) for i in range(2)]
	print(people[k][n-1])