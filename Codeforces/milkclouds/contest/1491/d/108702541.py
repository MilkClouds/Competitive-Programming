def f(x):
	a = []
	while x:
		a.append(x & 1)
		x //= 2
	return a + [0] * (30 - len(a))

for _ in range(int(input())):
	u, v = map(int, input().split())
	if u > v:
		print("NO")
		continue
	a, b = f(u), f(v)
	if a.count(1) < b.count(1):
		print("NO")
		continue
	flag = 0
	ac = bc = 0
	for i in range(30):
		bc += b[i]
		ac += a[i]
		if b[i] == 1 and a[i] == 0:
			if bc > ac:
				print("NO")
				flag = 1
				break
	if flag == 0:
		print("YES")
