"""
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5
"""

T=int(input())
l=[]
for i in range(T):
    l.append(list(map(int,input().split(' '))))

for i in l:
    a,b,r,c,d,r2=i
    if (a==c) and (b==d) and (r==r2): print(-1)
    elif (a==c) and (b==d): print(0)
    elif ( (a-c)**2+(b-d)**2 ) in ((r+r2)**2,(r-r2)**2): print(1)
    elif ( (a-c)**2+(b-d)**2 ) > ((r+r2)**2): print(0)
    elif ( (a-c)**2+(b-d)**2 ) < ((r-r2)**2): print(0)
    else: print(2)