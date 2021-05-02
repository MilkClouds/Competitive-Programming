n=int(input())
m=int(input())
t=[*map(int,input().split())]
ret=0
dic={}
for i in range(n):
    if dic.get(i): continue
    for j in range(i+1,n):
        if dic.get(j): continue
        if t[i]+t[j]==m:
            ret+=1
            dic[j]=1
print(ret)