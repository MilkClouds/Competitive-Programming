import sys
input=sys.stdin.readline
n=int(input())
s=sorted({int(input())for i in range(n)})
dic={}
for i in s:
    dic[i]=1
for i in range(n):
    j=n-i-1
    for k in range(j,-1,-1):
        for t in range(k,-1,-1):
            if dic.get(s[j]-s[k]-s[t]):
                print(s[j])
                exit()