import sys
for line in sys.stdin:
	P, B, N = map(int, line.split())
	T = int(P ** .5)
	table = {}
	table2 = {}
	ans = P
	for t in range(T, P, T):
		table[pow(B, t, P)] = t
	for l in range(T):
		table2[pow(B, l, P)] = l
	for i, j in table.items():
		tmp = pow(i, P - 2, P) * N % P
		if ~table2.get(tmp, -1):
			ans = min(ans, (j + table2[tmp]) % (P - 1))
	if pow(B, ans, P) == N:
		print(ans)
	else:
		print("no solution")

