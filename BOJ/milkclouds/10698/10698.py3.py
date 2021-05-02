for i in range(int(input())):
	a,b=map(eval,input().split('='));i+=1
	print('Case %d:'%i,'YES' if a==b else 'NO')