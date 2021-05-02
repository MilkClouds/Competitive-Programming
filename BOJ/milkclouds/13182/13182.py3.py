MOD = 10 ** 9 + 7
for _ in range(int(input())):
	R, G, B, K = map(int, input().split())
	a = (K + R) * pow(1 + B, K, MOD) * B - R * pow(B, K + 1, MOD) + G * K * pow(1 + B, K, MOD)
	a %= MOD
	b = B * pow(1+B, K, MOD)
	b %= MOD
	print(a * pow(b, MOD - 2, MOD) % MOD)