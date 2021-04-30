import sys,math
input=sys.stdin.readline

a,b,c=map(int,input().split())
if(a>b):a,b=b,a
t=b-a
if(c<=t):print((a+c)*2)
else:print(2*b+(c-t)//2*2)