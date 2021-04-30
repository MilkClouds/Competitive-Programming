a=input();b=input();c=input()

lcs=[[[0]*101 for i in range(101)] for i in range(101)]

act=[]
for x in range(2):
	for y in range(2):
		for z in range(2):
			if x+y+z in (0,3): continue
			act.append((-x,-y,-z))
for i in range(1,len(a)+1):
	for j in range(1,len(b)+1):
		for k in range(1,len(c)+1):
			if a[i-1]==b[j-1]==c[k-1]:
				lcs[i][j][k]=lcs[i-1][j-1][k-1]+1
			else:
				m=0
				for x,y,z in act:
						m=max(m,lcs[i+x][j+y][k+z])
				lcs[i][j][k]=m

print(lcs[len(a)][len(b)][len(c)])