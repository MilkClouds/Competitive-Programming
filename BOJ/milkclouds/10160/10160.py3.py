'''
d[i][j]를 j번 경우로 끝나는 i자리 암호라고 했을 때,

0번 경우 -> ABCB로 끝나는 경우
1번 경우 -> ABC로 끝나는 경우
2번 경우 -> AB로 끝나는 경우
3번 경우 -> A로 끝나는 경우
4번 경우 -> ABAB로 끝나는 경우
5번 경우 -> ABA로 끝나는 경우
6번 경우 -> 그 외의 경우
'''


r='''10000 3'''.split('\n')
r=iter(r)
#def input():
#	return next(r)

mod=1000_000_009
n,k=map(int,input().split())
d=[[0]*7 for i in range(2)]
d[1][3]=1
d[1][6]=k-1

for i in range(2,n+1):
	a=list(map(lambda x:x%mod,d[1]))
	i=0
	d[i][0]=a[1]
	d[i][1]=a[2]
	d[i][2]=a[3]
	d[i][3]=sum(a)-a[2]-a[4]
	d[i][4]=a[5]
	d[i][5]=a[2]+a[4]
	d[i][6]=a[6]*(k-1)+(a[0]+a[1]+a[2]+a[3]+a[4]+a[5])*(k-2)
	d[1]=d[0]

print(sum(d[1])%mod)