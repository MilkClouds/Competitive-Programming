import sys;input=sys.stdin.readline

pattern={}
for i in range(int(input())):
	a,b=map(int,input().split())
	if pattern.get(a): arr=pattern.get(a)
	else:
		arr=[]; num=a%10
		while (num!=(a)%10) or (not arr):
			arr.append(num)
			num=(num*a)%10
		pattern[a]=arr
	r=arr[(b-1)%len(arr)]
	print(10 if r==0 else r)