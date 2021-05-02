"""
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
"""

N=int(input())
DP=[0,0,1,1]
def t(i):
	return DP[int(i)] if i==int(i) else 10**10
for i in range(4,N+1):
	a=min(t(i-1),t(i/2),t(i/3))+1
	DP.append(a)
print(DP[N])