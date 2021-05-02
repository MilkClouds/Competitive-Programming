d = [0, 1]

for i in range(2, 81):
	d.append(d[i - 1] + d[i - 2])

N = int(input())
print(d[N] * 4 + d[N - 1] * 2)