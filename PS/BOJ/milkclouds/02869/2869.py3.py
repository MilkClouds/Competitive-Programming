a,b,v=map(int,input().split())
def t(a,b):
	if a%b: return a//b+1
	return a//b
print(t(v-a,a-b)+1)