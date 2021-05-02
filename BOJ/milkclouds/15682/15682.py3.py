from math import *
from decimal import *

getcontext().prec = 50

MAX = Decimal(1000000)
eps = 1e-40

def solve(l, r, rev = 1):
	while abs(r - l) > eps:
		m = (l + r) / 2
		if f(m) * rev > 0:
			r = m
		else:
			l = m
	return l;

for _ in range(int(input())):
	ans = set()
	A, B, C, D = map(Decimal, input().split())
	if A < 0:
		A *= -1
		B *= -1
		C *= -1
		D *= -1
	f = lambda i: A * i * i * i + B * i * i + C * i + D
	g = lambda i: 3 * A * i * i + 2 * B * i + C
	dis_g = B * B - 3 * A * C
	if dis_g < eps:
		l = -MAX
		r = MAX
		while abs(r - l) > eps:
			m = (l + r) / 2
			if f(m) > 0:
				r = m
			else:
				l = m
		print(l)
		continue
	lM = (-B - Decimal.sqrt(dis_g)) / (3 * A)
	lm = (-B + Decimal.sqrt(dis_g)) / (3 * A)
	if f(lM) < -eps:
		ans.add(solve(lm, MAX))
	elif f(lm) > eps:
		ans.add(solve(-MAX, lM))
	elif abs(f(lM)) <= eps:
		ans.add(solve(lm, MAX))
		ans.add(lM)
	elif abs(f(lm)) <= eps:
		ans.add(solve(-MAX, lM))
		ans.add(lm)
	else:
		ans.add(solve(-MAX, lM))
		ans.add(solve(lM, lm, rev = -1))
		ans.add(solve(lm, MAX))
	ans = sorted(ans)
	print(*ans)