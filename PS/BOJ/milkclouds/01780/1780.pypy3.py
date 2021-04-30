import sys
input=sys.stdin.readline

N=int(input())
pap=[list(map(int,input().split()))for i in range(N)]
ans=[0]*3

def solution(x,y,s):
	if s==1:
		return pap[x][y]
	r=[]
	for i in range(x,x+s,s//3):
		for j in range(y,y+s,s//3):
			r.append(solution(i,j,s//3))
	if len(set(r))==1 and r[0]!=None:
		return r[0]
	for i in r:
		if i==None: continue
		ans[1+i]+=1
	return None
t=solution(0,0,N)
if t!=None:
	ans[1+t]+=1
print(*ans,sep='\n')