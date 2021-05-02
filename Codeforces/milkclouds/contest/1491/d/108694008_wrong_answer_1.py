def f(x):
	a = []
	while x:
		a.append(x & 1)
		x //= 2
	return a

for _ in range(int(input())):
	u, v = map(int, input().split())
	if u > v:
		print("NO")
		continue
	a, b = f(u), f(v)
	for i in range(30):
		if a[i]:
			break
	for j in range(30):
		if b[j]:
			break
	if i > j or a.count(1) < b.count(1):
		print("NO")
		continue
	print("YES")
