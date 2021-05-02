a,b,c=map(int,input().split())
n = a*60*24+b*60+c - 11*60*24 - 11*60-11
print(-1 if n<0 else n)