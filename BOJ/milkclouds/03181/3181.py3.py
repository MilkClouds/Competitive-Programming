B = ['i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili']
for i, s in enumerate(input().split()):
	if i and s in B:
		continue
	print(s[0].upper(), end = '')
