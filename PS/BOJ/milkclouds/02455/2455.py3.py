l=[list(map(int,input().split(' '))) for i in range(4)]

p=0;re=[]

for i in l:
	p+=-i[0]+i[1]
	re.append(p)

print(max(re))