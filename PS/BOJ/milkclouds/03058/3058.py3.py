for i in range(int(input())):
	A=list(filter(lambda x: x%2-1,map(int,input().split())))
	print(sum(A),min(A))