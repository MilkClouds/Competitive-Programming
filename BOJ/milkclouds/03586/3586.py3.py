from fractions import *
f=Fraction
X = 1j
line=input().replace('X', str(X)).split()
S = []
BAN = []

class complexfrac:
	def __init__(self, a, b):
		self.real = f(a)
		self.imag = f(b)
	def __add__(self, x):
		return complexfrac(self.real + x.real, self.imag + x.imag)
	def __sub__(self, x):
		return complexfrac(self.real - x.real, self.imag - x.imag)
	def __mul__(self, x):
		return complexfrac(self.real * x.real, self.imag * x.real + self.real * x.imag)
	def __truediv__(self, x):
		return complexfrac(self.real / x.real, self.imag / x.real)
	def __repr__(self):
		return str(self.real)  + "+" + str(self.imag) + "j"

SWITCH = []

for d in line:
	if d in "+-*/":
		b = S.pop()
		a = S.pop()
		if d == '/':
			if a.real == 0 and a.imag == 0:
				S.append(complexfrac(0, 0))
				continue
			if b.imag != 0:
				BAN.append(- b.real / b.imag)
				SWITCH.append((a,b))
				S.append(complexfrac(0, 1))
			else:
				S.append(a / b)
		elif d == '*':
			S.append(a * b)
		elif d == '+':
			S.append(a + b)
		elif d == '-':
			S.append(a - b)
	else:
		d = complex(d)
		S.append(complexfrac(d.real, d.imag))
	

def get(x):
	if x.imag == 0:
		if x.real == 0: print("MULTIPLE")
		else: print("NONE")
		exit()
	else:
		return - x.real / x.imag

x = get(S[0])
while SWITCH:
	a, b = SWITCH.pop()
	if x == 0:
		print("NONE")
		exit()
	# print(a, b, x)
	# b / a = 1 / get(x)
	x = get(b - a / x)
print("X = %d/%d"%(x.numerator, x.denominator))

def get(x):
	if x.imag == 0:
		if x.real == 0: print("MULTIPLE")
		else: print("NONE")
		exit()
	else:
		return - x.real / x.imag