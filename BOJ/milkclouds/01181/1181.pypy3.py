A=set()
for i in range(int(input())):
	A.add(input())
A=list(A)
A.sort()
A.sort(key=lambda x:len(x))
print('\n'.join(A))