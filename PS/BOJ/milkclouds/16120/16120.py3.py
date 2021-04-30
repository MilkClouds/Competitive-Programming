st=input()
p=0
np=0
sr=st+'A'
for i,a in enumerate(st):
	if a=='P': p+=1
	elif (p>1 and sr[i+1]=='P'): p-=2
	else: np=1;break
print('NP' if (np or (p!=1) ) else 'PPAP')