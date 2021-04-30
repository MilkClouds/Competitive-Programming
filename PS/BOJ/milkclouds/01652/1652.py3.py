n=int(input())
g=[input().rstrip() for _ in range(n)]
g2=list(map(str.join,['']*n,zip(*g)))
r=0
for i in g:
	r+=i.count('..X')
	r+=1 if i.endswith('..') else 0
r2=r
r=0
g=g2
for i in g:
	r+=i.count('..X')
	r+=1 if i.endswith('..') else 0
print(r2,r)