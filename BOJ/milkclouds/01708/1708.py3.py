import sys
input=sys.stdin.readline

class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y
        self.p=self.q=0
    def __lt__(self,p):
        if self.p*p.q != self.q*p.p:
            return self.p*p.q > self.q*p.p
        if self.y != p.y:
            return self.y < p.y
        return self.x < p.x
    def __repr__(self):
        return str((self.x,self.y,self.p,self.q))
def ccw(A,B,C):
    return (A.y-C.y)*(A.x-B.x)-(A.y-B.y)*(A.x-C.x)

N=int(input())
p=[]
for _ in range(N):
    x,y=map(int,input().split())
    p.append(Point(x,y))
# 0번째 점은 가장 왼쪽 아래 점
p.sort()

for i in range(1,N):
    p[i].p=p[i].x-p[0].x
    p[i].q=p[i].y-p[0].y
# 왼쪽 아래 점 기준으로 반시계방향 정렬
p=[p[0]]+sorted(p[1:])

S=[0,1]
cur=2
while cur<N:
    while len(S)>=2:
        first=S.pop()
        second=S[-1]
        if ccw(p[second],p[first],p[cur])>0:
            S.append(first)
            break
    S.append(cur)
    cur+=1
print(len(S))