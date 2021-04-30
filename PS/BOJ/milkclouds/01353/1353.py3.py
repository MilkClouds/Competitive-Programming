S,P=map(int,input().split())
if S==P:
	print(1);exit()
n=1;prev=-1
while exec('n+=1') or 1:
	cur=(S/n)**n
	if cur<prev:
		print(-1)
		exit()
	if cur>=P:
		print(n)
		exit()
	prev=cur