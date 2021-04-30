input()
a=list(map(int,input().split()))
a.sort();r=0
for i,d in enumerate(a):
	r+=sum(a[:i])+d
print(r)