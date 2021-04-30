for i in range(int(input())):
	t=input()
	if t.endswith('y'):
		ans='nobody'
	elif t[-1] in ('a','e','i','o','u'):
		ans="a queen"
	else:ans="a king"
	print('Case #%d: %s is ruled by %s.'%(i+1,t,ans))