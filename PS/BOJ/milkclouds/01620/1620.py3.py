import sys
input=sys.stdin.readline
N,M=map(int,input().split())
dic={}
dicnum={}
for i in range(1,1+N):
    j=input().rstrip()
    i=str(i)
    dic[i]=j
    dicnum[j]=i

for _ in range(M):
    t=input().rstrip()
    if t.isdigit():
        print(dic[t])
    else:
        print(dicnum[t])
