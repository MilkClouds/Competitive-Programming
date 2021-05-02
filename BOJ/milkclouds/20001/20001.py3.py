input()
c = 0
while 1:
	x = input()
	if x[-1] == "끝":
		break
	if x[0] == "문":
		c += 1
	else:
		c = c - 1 if c > 0 else c + 2
print("힝구" if c else "고무오리야 사랑해")