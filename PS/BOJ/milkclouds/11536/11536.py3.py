N = int(input())
S = [input() for _ in range(N)]
C = sorted(S)

if S == C:
	print("INCREASING")
elif S[::-1] == C:
	print("DECREASING")
else:
	print("NEITHER")
