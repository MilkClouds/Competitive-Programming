for i in range(int(input())):
	s=input(); n=0
	for e in range(26):
		n+=0 if chr(e+65) in s else (e+65)
	print(n)