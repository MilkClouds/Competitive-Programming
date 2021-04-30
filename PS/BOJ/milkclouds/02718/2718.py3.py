import sys;input=sys.stdin.readline
D=[1,1]
m=[2,3][::-1]
i=2
while D[i-1]<(1<<31):
	t=D[i-1]+4*D[i-2]
	for k in range(3,i+1):
		t+=m[k%2]*D[i-k]
	D.append(t)
	i+=1
for _ in range(int(input())):
	n=int(input())
	print(D[n])
