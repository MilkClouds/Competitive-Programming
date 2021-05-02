a,b=map(int,input().split())
c=int(input())

t=60*a+b+c
print("%d %d"%(t//60%24,t%60))