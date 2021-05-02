import sys
input=sys.stdin.readline

while 1:
	t=input()[:-1]
	if t=='#': exit()
	print(len(set(filter(str.isalpha,t.lower()))))