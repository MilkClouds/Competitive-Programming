def round(t):
	if t*10-int(t*10)>=0.5: return (int(t*10)+1)/10
	return t

for _ in range(int(input())):
	grade=0;sc=0
	for _ in range(int(input())):
		a,b=map(float,input().split())
		grade+=a
		sc+=a*b
	print('%d %.1f'%(grade,round(sc/grade)))