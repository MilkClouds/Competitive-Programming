st=input()

s=''

pr=[0,0]; no=0; prev=''
d={'[':1, ']':-1, '(':1, ')':-1,'':0}
for i in st:
	if (prev,i) in (('(',')'),('[', ']')): s+='1'
	if (d[i],d[prev])==(1,-1) : s+='+'
	if (prev,i) in (('(', ']'), ('[',')')): no=1; break
	prev=i
	if i=='(':
		pr[0]+=1
		s+='2*('
	elif i==')':
		pr[0]-=1
		s+=')'
		if pr[0]<0: no=1; break
	elif i=='[':
		s+='3*('
		pr[1]+=1
	elif i==']':
		pr[1]-=1
		s+=')'
		if pr[1]<0: no=1; break

if (pr!=[0,0]) or no:
	print(0)
else: print(eval(s))