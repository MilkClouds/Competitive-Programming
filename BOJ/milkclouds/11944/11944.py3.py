n,m=map(int,input().split())
if n*len(str(n))>m:
 t=str(n)*(2016//len(str(n))+1)
else: t=str(n)*n
print(t[:m])