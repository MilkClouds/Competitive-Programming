import sys
input=sys.stdin.readline
s=input()[:-1]
key=input()[:-1]
len1=len(s)
len2=len(key)
def ppr(s):
	print(s,end='')
for i in range(len1):
	if s[i]==' ':
		ppr(' ')
		continue
	t=ord(s[i])-ord(key[i%len2])-1
	ppr(chr(t%26+97))