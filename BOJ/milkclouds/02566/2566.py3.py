A=[]
for i in range(9):
	for i in map(int,input().split()):
		A.append(i)
print(max(A))
P=A.index(max(A))
print(P//9+1,P%9+1)