a, b = map(int, input().split())
c, d = divmod(a, b)
if d < 0:
	d -= b
	c += 1
print(c, d, sep = '\n')