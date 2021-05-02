a,b,c=map(int,input().split())
d=int(input())

t=3600*a+60*b+c+d
print("%d %d %d"%(t//3600%24,(t%3600)//60,t%60))