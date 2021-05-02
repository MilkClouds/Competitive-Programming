import sys
input=sys.stdin.readline
MAX = 10000 * 2 + 2
bias = 10000 + 1

def query(i):
	ret = 0
	while i:
		ret += tree[i]
		i ^= i & -i
	return ret
def update(i, x):
	while i < MAX:
		tree[i] += x
		i += i & -i

tree = [0] * MAX
for k in range(int(input())):
	i = int(input())
	update(i + bias, 1)
	L, R = 1, MAX
	T = (k + 1) // 2 + (k + 1) % 2
	while L < R:
		M = L + R >> 1
		if query(M) < T:
			L = M + 1
		else:
			R = M
	print(L - bias)


	