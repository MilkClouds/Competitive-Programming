import re,sys
input=sys.stdin.readline
n=int(input())
for ii in range(n):
	a=input().strip().lower()
	b=input().strip().lower()
	for i in ['[','{']:
		a=a.replace(i,'(')
		b=b.replace(i,"(")
	for i in [']','}']:
		a=a.replace(i,')')
		b=b.replace(i,")")
	a=a.replace(';',',')
	b=b.replace(';',',')
	a=re.sub('\s+',' ',a)
	b=re.sub('\s+',' ',b)
	s=r'()[]{}.,;:'
	for i in s:
		i='\\'+i
		b=re.sub('\s?'+i+'\s?',i,b)
		a=re.sub('\s?'+i+'\s?',i,a)
	print('Data Set %d:'%(ii+1),("" if a==b else 'not ')+'equal')
	print()