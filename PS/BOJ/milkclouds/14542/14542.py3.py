TC = 0
while 1:
	TC += 1
	n = int(input())
	if n == 0:
		break
	a = 0
	for i in range(n):
		x = [*map(int, input().split())]
		if i == n - 1:
			a += sum(x)
		elif i:
			a += x[0] + x[-1]
		else:
			a += x[0]
	print("Case #%d:%d" % (TC, a))
