import sys
input=sys.stdin.readline
n,m,q=map(int,input().split())
score=[[0]*m for i in range(n)]
solved=[set() for i in range(n)]

for i in range(q):
	t=input().split()
	time,team,qno,re=[int(i)-1 for i in t[:3]]+[t[3]]
	if qno in solved[team]: continue
	target=score[team][qno]
	if re!='AC':
		target+=20
	else:
		target+=time+1
		solved[team].add(qno)
	score[team][qno]=target

#team,questions,time
ans=[]
for i in range(n):
	a=sum([score[i][e] for e in solved[i]])
	ans.append((i,a,len(solved[i])))

ans=sorted(ans,key=lambda x:x[1])
ans=sorted(ans,key=lambda x:x[2],reverse=1)

for a,b,c in ans:
	print(a+1,c,b)