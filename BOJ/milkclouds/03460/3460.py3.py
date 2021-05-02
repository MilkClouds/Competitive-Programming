for i in range(int(input())):
	num=int(input())
	for i in range(num.bit_length()):
		if num&(1<<i):
			print(i,end=' ')
	print()
		