n,x=map(int, input().split())
for i, j in enumerate(map(int, input().split())):
	if i & 1:
		j -= 1
	x -= j
print("Yes" if x >= 0 else "No")