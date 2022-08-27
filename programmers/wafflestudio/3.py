A=eval(input())
N=len(A)
B=[1]*N
S=[]
x=0
def prv(x):
    for i in range(x-1,-1,-1):
        if B[i]:
            return i
    raise Exception("Error 100")
def nxt(x,d=0):
    for i in range(x + 1, N):
        if B[i]:
            return i
    if d:
        return prv(x)
    raise Exception("Error 100")
while 1:
    c=input()
    if c=='q':
        break
    if c=='delete':
        B[x]=0
        S.append(x)
        x=nxt(x,1)
    elif c=='restore':
        if S:
            y=S.pop()
            B[y]=1
        else:
            print("Error 200")
    elif c=='list':
        print(*[A[i] for i in range(N) if B[i]], sep='\n')
    else:
        _,a,b=c.split()
        y=x
        try:
            for _ in range(int(b)):
                y=nxt(y) if a=='-d' else prv(y)
        except Exception as e:
            print(e)
        else:
            x=y