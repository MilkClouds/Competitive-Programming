def add(a):
	if a==25+65: return 65
	return a+1
for i in range(int(input())):
	print('String #%d'%(i+1))
	print(''.join([chr(add(ord(i))) for i in input()]))
	print()