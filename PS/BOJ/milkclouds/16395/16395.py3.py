import sys,math
input=sys.stdin.readline

n,k=map(int,input().split())
n-=1;k-=1
def fact(n):
	r=1
	for i in range(2,n+1):
		r*=i
	return r
print(fact(n)//fact(n-k)//fact(k))