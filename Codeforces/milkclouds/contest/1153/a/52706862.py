import sys
input=sys.stdin.readline

N,T=map(int,input().split())
candidate=[]
for i in range(N):
    s,d=map(int,input().split())
    # s+d*i>=T
    # (T-s)/d
    if T<s:
        candidate.append((s,i+1))
    else:
        candidate.append((s+((T-s)//d+((T-s)%d!=0))*d,i+1))

candidate.sort(key=lambda x:x[0])
print(candidate[0][1])