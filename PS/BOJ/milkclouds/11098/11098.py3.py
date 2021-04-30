for _ in range(int(input())):
	r=0;name=''
	for i in range(int(input())):
		a,b=input().split()
		a=int(a)
		if r<a:
			name=b
			r=a
	print(name)