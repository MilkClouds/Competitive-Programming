import sys
input=sys.stdin.readline
for _ in range(int(input())):
	a=0
	for i in range(int(input())):
		x,y=input().split()
		if x=='R':
			if y=='P':
				a-=1
			elif y=='S':
				a+=1
		elif x=='S':
			if y=='R':
				a-=1
			elif y=='P':
				a+=1
		elif x=='P':
			if y=='S':
				a-=1
			elif y=='R':
				a+=1
	print(('Player 1' if a>0 else 'Player 2') if a else 'TIE')