class line:
	def __init__(self,a,b):
		self.a=a
		self.b=b
	def query(self,li):
		if type(li)==int:
			print('POINT %.2f %.2f'%(li,self.a*li+self.b))
			return
		if self.a==li.a:
			if self.b==li.b:
				print('LINE')
			else:
				print('NONE')
		else:
			x=(self.b-li.b)/(li.a-self.a)
			y=self.a*x+self.b
			print('POINT %.2f %.2f'%(x,y))
for i in range(int(input())):
	a,b,c,d,*t=map(int,input().split())
	# y=(d-b)/(c-a)*(x-a)+b
	if c==a:
		l=c
	else:
		m=(d-b)/(c-a)
		l=line(m,-m*a+b)
	a,b,c,d=t
	if c==a:
		if type(l)==int:
			print('LINE' if l==a else 'NONE')
		else:
			l.query(c)
	else:
		m=(d-b)/(c-a)
		l2=line(m,-m*a+b)
		l2.query(l)