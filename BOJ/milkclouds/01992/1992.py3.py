import sys
input=sys.stdin.readline

#input=open('python.in').readline

n=int(input())
g=[input().rstrip() for _ in range(n)]

def solution(size,x,y):
	if size==1:
		return g[y][x]
	ns=size//2
	t=[solution(ns,x,y),solution(ns,x+ns,y),solution(ns,x,y+ns),solution(ns,x+ns,y+ns)]
	if len(set(t))==1 and t[0] in ('0','1'):
		return t[0]
	return '(%s%s%s%s)'%tuple(t)

t=solution(n,0,0)
print(t)