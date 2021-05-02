import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=[]
for i in range(n):
    a.append(float(input()))
a.sort()
print("%.2f"%(sum(a[k:n-k])/(n-k-k)+1e-9))
print("%.2f"%(((a[k]+a[n-k-1])*k+sum(a[k:n-k]))/n+1e-9))