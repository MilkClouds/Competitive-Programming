import math
m,n,r=map(float,input().split())
ax,ay,bx,by=map(int,input().split())

print(min(abs(ax-bx)/m*i/n*r*math.pi+(abs(ay-i)+abs(by-i))/n*r for i in range(int(n)+1)))