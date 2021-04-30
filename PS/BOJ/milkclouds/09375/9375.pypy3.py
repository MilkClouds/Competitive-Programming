def mul(t):
	a=1
	for i in t:
		a*=i+1
	return a
for i in range(int(input())):
	dic={}
	for i in range(int(input())):
		a,b=input().split(' ')
		dic[b]=dic.get(b,0)+1
	print(mul(dic.values())-1)