import sys
input=sys.stdin.readline

N=int(input())
A=[]; freq={}
for i in range(N):
	i=int(input())
	A.append(i)
	freq[i]=freq.get(i,0)+1

def round(a):
	i=int(a) if a>0 else (int(a)-1)
	if a>=i+0.5: return i+1
	else: return i

"""
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.
"""
A.sort()
print(round(sum(A)/N))
print(A[N//2])

freq=sorted(freq.items(),key=lambda x:x[0])
#print(freq)
freq=sorted(freq,key=lambda x:x[1],reverse=1)
#print(freq)
if len(freq)==1: print(A[0])
else:
	if freq[0][1]==freq[1][1]:
		print(freq[1][0])
	else: print(freq[0][0])

print(A[-1]-A[0])