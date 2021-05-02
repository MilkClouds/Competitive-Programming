import sys
input=sys.stdin.readline
sys.setrecursionlimit(99999)
n=int(input())
a=sorted(map(int,input().split()))+[0]
limit=int(input())
def find(pseudo,current):
    if current==n:
        print(a[-2])
        exit()
    if pseudo<=limit:
        current+=1
        pseudo+=(a[current]-a[current-1])*(n-current)
        return find(pseudo,current)
    else:
        return pseudo,current
pseudo,current=find(a[0]*n,0)
limit-=sum(a[:current])
def solution(start,end):
    if start==end-1:return start
    # print(start,end)
    mid=(start+end)//2
    prev,nex=current+1,n-current
    pseudo=nex*mid
    if pseudo<limit:
        return solution(mid,end)
    elif pseudo>limit:
        return solution(start,mid)
    return mid
t=solution(a[current-1],a[current])
print(t)