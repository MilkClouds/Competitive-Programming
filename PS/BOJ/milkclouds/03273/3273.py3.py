import sys
input=sys.stdin.readline
n=int(input())
d={}
for i,j in enumerate(map(int,input().split())):
    d[j]=i+1

x=int(input())
cnt=0
for i in d.keys():
    if d.get(x-i) and d[x-i]<d[i]:
        cnt+=1
print(cnt)