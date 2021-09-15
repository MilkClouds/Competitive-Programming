import sys

n=int(input())
a=[*map(int,input().split())]
chk=[];chk2=[];zero=0
for i in a:
    if i<0:
        chk.append(i)
    elif i>0:
        chk2.append(i)
    else:
        zero+=1

t=0
if len(chk)%2==0 or (len(chk)%2==1 and zero):
    t=-len(chk)-sum(chk)
else:
    t=-len(chk)-sum(chk)+2

print(sum(chk2)-len(chk2)+t+zero)