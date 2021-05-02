import sys,re
d={}
for i in re.finditer('[a-zA-Z\-]+',sys.stdin.read()[:-5]):
	i=i[0]
	l=len(i)
	d.setdefault(l,i)
print(d[max(d)].lower())