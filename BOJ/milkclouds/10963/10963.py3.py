

#input=open("10960/calvin3.in").readline

#pr=open("h2.out","w").write
ppp=print
def pr(*a):
	ppp(*a,end='')
def print(*a):
	return

n,m=map(int,input().split())
teams=[]
arr=[set() for i in range(1+n)]

for i in range(m):
	a,b=map(int,input().split())
	arr[a].add(b)
	arr[b].add(a)
	if i%100==0:print(i,'..')
print("arr complete")

print(arr)
best='1'*1000
def solution(teams,cur):
	global best
	if cur==n+1:
		if len(teams)<len(best):
			best=teams
		return
	for num in range(cur,cur+1):
		proc=0
		if num%100==0: print(num)
		for i,j in enumerate(teams):
			if not arr[num]&j:
				t=[i.copy() for i in teams]
				t[i].add(num);proc=0
				solution(t,cur+1)
		if not proc:
			if len(teams)>=len(best):return
			teams.append(set((num,)))
			solution(teams,cur+1)
			
solution([],1)
teams=best
print(len(teams))
pr(str(len(teams)))
pr('\n')
for i in teams:
	print(*i)
	pr(' '.join(map(str,i)))
	pr('\n')