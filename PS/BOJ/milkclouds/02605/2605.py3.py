n=int(input())
a=[]
idx=0
for i in map(int,input().split()):
	idx+=1
	a.insert(idx-1-i,idx)
print(*a)