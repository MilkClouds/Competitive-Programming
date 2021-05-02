N = int(input())
A = [''] * 101
M = 0
for i in range(N):
	A[i] = input().replace('-1', '').split()
	M = max(M, len(A[i]))

for i in range(N):
	A[i] += ['0'] * (M - len(A[i]))
	A[i] = tuple(A[i])

for i in range(M):
	S = set()
	for j in range(N):
		S.add(A[j][:i + 1])
	if len(S) == N:
		print(1 + i)
		exit()