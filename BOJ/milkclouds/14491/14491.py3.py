n=int(input())
for i in range(1,1029209):
	if '9' in str(i): continue
	if n==int(str(i),9): print(i);exit()