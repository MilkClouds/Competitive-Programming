n=int(input())
v=[]
for _ in range(n):
	s,e=map(int,input().split())
	v.append((s,e))
v.sort()

ret=0
for i in range(n):
	if ret<v[i][0]:ret=v[i][0]
	ret+=v[i][1]
print(ret)