def ddel(S, i, s):
	if len(S) == i or S[i] != s:
		return 0
	return 1
for _ in range(int(input())):
	S = input()
	flag = i = 0
	d = {}
	while i < len(S):
		d[S[i]] = d.get(S[i], 0) + 1
		if d[S[i]] % 3 == 0:
			if not ddel(S, i + 1, S[i]):
				flag = 1
				break
			i += 1
		i += 1
	print("FAKE" if flag else "OK")
