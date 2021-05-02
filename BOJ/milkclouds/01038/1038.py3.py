D=[]
queue=[0,1,2,3,4,5,6,7,8,9]
def diminishing():
	while queue:
		element=queue.pop(0)
		D.append(element)
		for i in range(int(str(element)[-1])):
			queue.append(10*element+i)

diminishing()
N=int(input())
if N>len(D)-1: print(-1)
else: print(D[N])