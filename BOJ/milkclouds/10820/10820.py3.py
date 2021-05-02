import sys
for line in sys.stdin:
	a,b,c=[0]*3
	for s in line:
		if s.islower():a+=1
		elif s.isupper():b+=1
		elif s.isdigit():c+=1
	print(a,b,c,len(line)-a-b-c-1)