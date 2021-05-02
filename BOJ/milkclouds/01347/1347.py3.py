maze=[['#']*99 for i in range(99)]

n=int(input())
cmd=input()
cur=[49,49,1]
maze[49][49]='.'

def L():
	cur[2]=(cur[2]-1)%4
def R():
	cur[2]=(cur[2]+1)%4

act=((1,0),(0,1),(-1,0),(0,-1))
for c in cmd:
	if c=='F':
		a,b=cur[:2]
		c,d=act[cur[2]]
		cur[:2]=[a+c,b+d]
		maze[b+d][a+c]='.'
	else: eval(c+'()')

m=maze.copy()
ind=len(maze)
r1=100;r2=0
for i in maze[::-1]:
	ind-=1
	if not i.count('.'): m.pop(ind);continue
	r1=min(r1,i.index('.'))
	r2=max(r2,98-i[::-1].index('.'))
maze=m
for i in maze:
	del i[r2+1:]
	del i[:r1]

for i in maze:
	print(''.join(i))