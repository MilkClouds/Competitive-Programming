import sys
input=sys.stdin.readline
n=int(input())

def func(tt):
    tt=int(tt.replace('0','9').replace('6','9'))
    return min(tt,100)
s=sum(func(input()) for _ in range(n))
print('%.0f'%(s/n+1e-10))