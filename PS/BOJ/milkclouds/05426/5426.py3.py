for _ in range(int(input())):
	S = input()
	N = int(len(S) ** .5)
	assert(N * N == len(S))
	for i in range(N):
		for j in range(N):
			print(S[N - i - 1 + N * j], end = '')
	print()
