def G(a,b):
    if a<b: a,b=b,a
    if b==0: return a
    while a%b:
        a,b=(b,a%b)
    return b
input()

s=[int(i) for i in input().split(' ')]
for i in s[1:]:
	g=G(s[0],i)
	print('%d/%d'%(s[0]//g,i//g))