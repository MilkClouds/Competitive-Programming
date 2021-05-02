def sub(a,b):
	return ord(b)-ord(a) if a<=b else 26+ord(b)-ord(a)

for _ in range(int(input())):
	a,b=input().split()
	print('Distances:',*[sub(i,j) for i,j in zip(a,b)])