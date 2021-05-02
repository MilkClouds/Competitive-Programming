S = input()
N = int(input())
A = [''] * 100
D = {}
dp = [1] + [0] * 100
for i in range(N):
	A[i] = input()
	D[A[i]] = 1


for i in range(len(S)):
	for j in range(i + 1):
		if dp[j]:
			if D.get(S[j:i+1]):
				dp[i + 1] = 1
				break

print(dp[len(S)])
