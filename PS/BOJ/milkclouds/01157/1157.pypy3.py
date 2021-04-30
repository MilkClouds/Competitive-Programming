r=input()
r=r.lower()
l=[0]*26
for i in r:
	l[ord(i)-97]+=1
if l.count(max(l))>1:
	print('?')
else: print(chr(65+l.index(max(l))))