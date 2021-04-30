import sys
input=sys.stdin.readline

n=int(input())
st=input()[:-1]

p='''ACAG
CGTA
ATCG
GAGT'''.split('\n')

def s(a,c):
	b[a]=c
	return 1
e='AGCT'
a={}
for i in range(4):
	b={}
	[s(e[j],p[i][j]) for j in range(4)]
	a[e[i]]=b
for i in range(n-1,0,-1):
	st= st[:i-1]+ a[st[i-1]][st[i]]
print(st)