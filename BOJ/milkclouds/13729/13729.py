F = [0, 1, 1]
MOD = 10 ** 13
for _ in range(1000):
    F.append((F[-1] + F[-2]) % MOD)
print(F)