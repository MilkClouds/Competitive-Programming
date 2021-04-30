import sys;input=sys.stdin.readline

MAX=100000
arr=[1]*MAX;pn=[2]
for i in range(3,MAX,2):
    if arr[i]==0: continue
    pn.append(i)
    for e in range(i*i,MAX,i*2): arr[e]=0

memo=[{} for i in range(100001)]
for i in range(int(input())):
    n=int(input())
    for i in pn:
        if n<i: break
        if n%i==0:
            if memo[n].get(i)!=None: print(memo[n][i])
            else:
                m=n;index=0
                while m and m%i==0: m//=i; index+=1
                memo[n][i]=index
                print(i,index)
