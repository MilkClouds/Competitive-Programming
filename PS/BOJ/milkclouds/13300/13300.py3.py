import sys
input=sys.stdin.readline

N,K=map(int,input().split())
a=[[0,0] for _ in range(6)]
for _ in range(N):
	S,Y=map(int,input().split())
	a[Y-1][S]+=1
def t(a,b):
	if a%b==0: return a//b
	else: return a//b+1
print(sum([t(x,K)+t(y,K) for x,y in a]))