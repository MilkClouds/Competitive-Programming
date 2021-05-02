n=int(input())
size=[list(map(int,input().split())) for i in range(n)]

def compare(x,y):
	if x[0]>y[0] and x[1]>y[1]: return 1
	elif list(map(lambda x,y:x<y,x,y))==[1,1]:
		return -1
	return 0

ret=[1]*n
for x in range(n):
	for y in range(n):
		if x==y: continue
		re=compare(size[x],size[y])
		if re==1:
			ret[y]+=1
print(*ret)