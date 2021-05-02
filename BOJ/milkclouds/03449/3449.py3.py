for i in range(int(input())):
	a,b=[int(input(),2) for i in range(2)]
	print('Hamming distance is %d.'%(str(bin(a^b)).count('1')))