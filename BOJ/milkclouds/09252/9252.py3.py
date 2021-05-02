a=input();b=input()
lcs=[[0]*(len(b)+1) for i in range(len(a)+1)]
for i in range(1,len(a)+1):
	for j in range(1,len(b)+1):
		if a[i-1]==b[j-1]:
			lcs[i][j]=lcs[i-1][j-1]+1
		else:
			lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])

print(lcs[len(a)][len(b)])

x,y=len(a),len(b);s=''
while lcs[x][y]!=0:
	if lcs[x][y]==lcs[x-1][y]: x-=1
	elif lcs[x][y]==lcs[x][y-1]: y-=1
	else:
		x-=1;y-=1
		s=a[x]+s
print(s)