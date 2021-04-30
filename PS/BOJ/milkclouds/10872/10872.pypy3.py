def fact(i):
	b=1
	for a in range(2,i+1):
		b*=a
	return b

print(fact(int(input())))