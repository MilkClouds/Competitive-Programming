N=int(input()); no=0
stack=[1]; act=['+']
K=[]
for i in range(N):
	K.append(int(input()))

index=1
for i in K:
	d=stack[-1] if stack else 0
	if d>i:
		try:
			while i != stack.pop(): act.append('-')
		except: no=1; break
	else:
		for j in range(i-index):
			index+=1
			act.append('+')	
			stack.append(index)
	if not stack: no=1; break
	act.append('-'); stack.pop()
	
print('NO' if no else '\n'.join(act))