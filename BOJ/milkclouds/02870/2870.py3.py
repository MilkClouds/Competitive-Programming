import re
reg=re.compile('\d+')
n=int(input());ret=[]
for i in range(n):
	[ret.append(int(i)) for i in re.findall(reg,input())]
print(*sorted(ret),sep='\n')