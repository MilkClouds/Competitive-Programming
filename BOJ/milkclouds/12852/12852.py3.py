N=int(input())
DP=[0,(0,0),(1,1),(1,1)]
def t(i):
	return DP[int(i)][0] if i==int(i) else 10**10
def mi(s):
	global i
	m=min(s)
	if m==s[0]:
		return m+1,i-1
	elif m==s[1]:
		return m+1,i//2
	else:return m+1,i//3
for i in range(4,N+1):
	r=t(i-1),t(i/2),t(i/3)
	DP.append(mi(r))
print(DP[N][0])
ret=[];cur=N
for i in range(DP[N][0]+1):
	ret.append(cur)
	cur=DP[cur][1]
print(*ret)