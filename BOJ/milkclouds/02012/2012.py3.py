import sys
input=sys.stdin.readline
n=int(input())
a=sorted(int(input())for _ in range(n))
cur=1;ans=0
for i in a:
	ans+=abs(i-cur)
	cur+=1
print(ans)