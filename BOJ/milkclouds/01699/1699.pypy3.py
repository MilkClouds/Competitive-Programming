import sys
sys.setrecursionlimit(100000)

nn=int(input())

d=[100000]*100001

ex=[i*i for i in range(1,320)]

result=nn

def dfs(n,count):
	global nn,result
	if d[n]>count: d[n]=count
	else: return
	if n==0: result=min(result,count)
	for i in ex[::-1]:
		if i>n: continue
		if count>=result: continue
		dfs(n-i,count+1)
		
dfs(nn,0)
print(result)