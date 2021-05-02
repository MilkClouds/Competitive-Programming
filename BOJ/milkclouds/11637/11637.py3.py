import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    A=[(int(input()),i) for i in range(1,1+n)]
    A.sort(reverse=1)
    S=sum(map(lambda x:x[0],A))
    if A[0][0]==A[1][0]: print('no winner')
    else:
        print('minority' if S//2>=A[0][0] else 'majority','winner',A[0][1])