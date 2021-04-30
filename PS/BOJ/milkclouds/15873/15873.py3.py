t=input()
if len(t)==4:print(20)
elif len(t)==3:
	if t[:2]=='10':
		print(int(t[:2])+int(t[2]))
	elif t[1:]=='10':
		print(int(t[0])+int(t[1:]))
else:
	print(sum(map(int,t)))