n,m=map(int,input().split())
def mul(a):
	r=1
	for i in a:
		r=(r*i)%m
	return r
print(mul(map(int,input().split())))