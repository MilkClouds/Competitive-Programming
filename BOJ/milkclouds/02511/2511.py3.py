MI = lambda: [*map(int, input().split())]

A = MI()
B = MI()
l = x = y = 0

for i, a in enumerate(A):
	if a > B[i]:
		x += 3
		l = 1
	elif a == B[i]:
		x += 1
		y += 1
	else:
		y += 3
		l = 2

print(x, y)
if x == y and l == 0:
	print("D")
elif x == y and l:
	print("A" if l == 1 else "B")
else:
	print("A" if x > y else "B")