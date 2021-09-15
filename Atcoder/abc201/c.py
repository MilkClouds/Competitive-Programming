ans = 0
S = input()
a = set()
b = set()
for i in range(10):
	if S[i] == 'o':
		a.add(str(i))
	elif S[i] == 'x':
		b.add(str(i))
for i in range(10000):
	i = "%04d" % i
	if set(i) & b: continue
	if len(set(i) & a) != len(a): continue
	ans += 1
print(ans)