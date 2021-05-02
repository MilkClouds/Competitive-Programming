N, K = map(int,input().split())
def f(a):
	b = []
	for i in range(len(a) - 1):
		b.append(a[i + 1] - a[i])
	return b
def ff(a, i):
	for _ in range(i):
		a = f(a)
	return a

print(*ff([*map(int,input().split(','))], K), sep = ',')