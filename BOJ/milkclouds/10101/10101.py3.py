a,b,c=map(int,[input() for i in range(3)])

'''Equilateral
세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
세 각의 합이 180이 아닌 경우에는 Error
'''
if a==b==c==60:
	print('Equilateral')
elif a+b+c!=180: print('Error')
elif len(set((a,b,c)))==2: print("Isosceles")
else: print("Scalene")