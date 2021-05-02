def valid(S):
	a = 0
	for i in S:
		if i == '(':
			a += 1
		else:
			a -= 1
		if a < 0:
			return 0
	return a == 0
for _ in range(int(input())):
	S = input()
	flag = \
	valid(S.replace('A', '(').replace('B', '(').replace('C', '(')) or\
	valid(S.replace('A', '(').replace('B', '(').replace('C', ')')) or\
	valid(S.replace('A', '(').replace('B', ')').replace('C', '(')) or\
	valid(S.replace('A', '(').replace('B', ')').replace('C', ')')) or\
	valid(S.replace('A', ')').replace('B', '(').replace('C', '(')) or\
	valid(S.replace('A', ')').replace('B', '(').replace('C', ')')) or\
	valid(S.replace('A', ')').replace('B', ')').replace('C', '(')) or\
	valid(S.replace('A', ')').replace('B', ')').replace('C', ')'))
	print("YES" if flag else "NO")