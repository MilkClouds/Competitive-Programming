MI = lambda: map(int, input().split())

N, Q = MI()
A = [*MI()]
B = [0] * 2
for i in A:
	B[i] += 1

for _ in range(Q):
	t, x = MI()
	if t == 1:
		x -= 1
		B[A[x]] -= 1
		B[A[x] ^ 1] += 1
		A[x] ^= 1
	else:
		if x > B[1]:
			print(0)
		else:
			print(1)
