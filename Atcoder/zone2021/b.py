MI = lambda: map(int, input().split())
N, D, H = MI()
ans = 0
for _ in range(N):
	d, h = MI()
	ans = max(ans, H - D * (H - h) / (D - d))
print(ans)