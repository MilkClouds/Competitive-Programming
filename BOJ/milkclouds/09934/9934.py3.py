K=int(input())
d={}
def sol(a,n):
	d[n]=d.get(n,[])+[a[n//2]]
	if n==1:return
	n//=2
	sol(a[:n],n)
	sol(a[n+1:],n)
sol(list(map(int,input().split())),(1<<K)-1)
for i in range(K):
	print(*d[(1<<K-i)-1])