import sys
for line in sys.stdin:
	a,b=line.split()
	if a==b=='0':break
	olim=0;ret=0
	a='0'*(len(b)-len(a))+a
	b='0'*(len(a)-len(b))+b
	for i,j in zip(a[::-1],b[::-1]):
		t=int(i)+int(j)+olim
		olim=t//10
		ret+=olim
	print(ret)