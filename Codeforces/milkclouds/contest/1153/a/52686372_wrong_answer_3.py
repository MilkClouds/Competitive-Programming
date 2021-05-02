import sys
input=sys.stdin.readline

N,T=map(int,input().split())
candidate=[]
for i in range(N):
    s,d=map(int,input().split())
    candidate.append(((T-s+d*100000)%d,i+1))

candidate.sort(key=lambda x:x[0])
print(candidate[0][1])