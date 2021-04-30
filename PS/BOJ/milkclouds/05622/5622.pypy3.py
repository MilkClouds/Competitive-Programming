t=0
for i in input():
	s=ord(i)-65
	if s<15: s//=3
	else:
		if s<19: s=5
		elif 21<s<26: s=7
		else: s=6
	t+=s+3
print(t)