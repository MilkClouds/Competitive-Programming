N,K=[int(i) for i in input().split(' ')]
coins=[int(input()) for i in range(N)]
coins.sort(reverse=1)
rem=K; res=0
for i in coins:
	n=rem//i
	rem-=n*i
	res+=n
print(res)