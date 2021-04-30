for _ in range(int(input())):
	a,b,c=map(int,input().split())
	b-=c
	if a<b:print("advertise")
	elif a>b:print('do not advertise')
	else:print('does not matter')