n,b=map(int,input().split());r=''
def t(a):
	if a>=10: return chr(65+a-10)
	return str(a)
while n:
	r+=t(n%b)
	n=n//b
print(r[::-1])