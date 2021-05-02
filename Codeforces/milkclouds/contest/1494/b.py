for _ in range(int(input())):
	n, U, R, D, L = map(int, input().split())
	flag = 0
	for i in range(2):
		if flag: break
		for j in range(2):
			if flag: break
			for k in range(2):
				if flag: break
				for l in range(2):
					a, b, c, d = U - i - j, R - j - k, D - k - l, L - l - i
					if 0 <= a <= n - 2 and 0 <= b <= n - 2 and 0 <= c <= n - 2 and 0 <= d <= n - 2:
						flag = 1
						break
	print("YES" if flag else "NO")