t=input()
i=t.find('x')
if i==-1:
	print(0)
else:
	print(t[:i] if (t[:i] not in("","-")) else t[:i]+'1')