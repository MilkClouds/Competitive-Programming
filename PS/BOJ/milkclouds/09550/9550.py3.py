for i in range(int(input())):
	n,k=map(int,input().split())
	print(sum([e//k for e in map(int,input().split())]))