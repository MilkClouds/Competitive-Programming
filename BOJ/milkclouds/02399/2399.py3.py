import sys
input=sys.stdin.readline
n=int(input())
a=sorted(map(int,input().split()))
s=[0]
ans=0
for i in range(n):
	s.append(s[i]+a[i])
for i in range(n):
	t=a[i]
	ans+=-s[i]+i*t+s[n]-s[1+i]-(n-i-1)*t
print(ans)