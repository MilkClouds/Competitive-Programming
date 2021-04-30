N = int(input())
A = [*map(int, input().split())]
B = sorted(set(A))
d = {}
for i, j in enumerate(B):
	d[j] = i
for i in range(N):
	print(d[A[i]], end = ' ')
