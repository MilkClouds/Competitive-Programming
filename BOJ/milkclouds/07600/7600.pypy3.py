while 1:
	t=input()
	if t=='#': exit()
	print(len(set(filter(str.isalpha,t.lower()))))