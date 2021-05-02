import sys
for line in sys.stdin:
	line = line.rstrip()
	if line == '*':
		break
	print("Y" if len(set(i.lower()[0] for i in line.split())) == 1 else "N")