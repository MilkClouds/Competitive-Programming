import sys
input=sys.stdin.readline
a=[]
for i in range(int(input())):
    a.append(input().rstrip())

def func(t):
    return sum(map(int,filter(str.isdigit,t)))

a.sort()
a.sort(key=func)
a.sort(key=lambda x:len(x))
for i in a:print(i)
