for _ in range(int(input())):
	N=int(input())
	ret=0
	for n in range(2,N):
		if 2*N<=(n-1)*n:
			break
		if (2*N)%n==0:
			if (2*N//n-n+1)%2==0:
				ret+=1
	print(ret)