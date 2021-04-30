N=int(input())

def calc(N):
    s=str(N)
    return int(s[-1]+str(+N//10+N%10)[-1])

T=calc(N);index=0
while 1:
    index+=1
    if T==N: break
    T=calc(T)

print(index)