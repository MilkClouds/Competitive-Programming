import sys
input=sys.stdin.readline

N=int(input())
A=[]
for _ in range(N):
	s,e=map(int,input().split())
	A.append((e,s))

A.sort()
# tuple(a,b) < tuple(c,d)은 일단 a<c 비교하고, a==c이면 b<d로 비교한다.
# ex) (1,2)<(3,4)이고, (1,3)<(1,4)
# 끝나는 시간 기준으로 오름차순 정렬한다.
# 끝나는 시간이 빠른 회의를 일단 하도록 고르면 최적해가 되기 때문
# 끝나는 시간이 같으면 시작시간 빠르게 정렬한다.
# 이유는 찬찬히 생각해보자. 회의의 시작시간과 끝나는 시간이 같을 수도 있으며, 한 회의가 끝나는 것과 동시에 다른 회의가 시작될 수 있는 것을 생각해보자.


last=ans=0
for e,s in A:
	if last<=s:
		ans+=1
		last=e
print(ans)
