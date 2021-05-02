A,B,C=list(map(int,input().split(' ')))

def pow(a,b):
    if b==0: return 1
    if b%2==0: return (pow(a,b//2)**2)%C
    elif b%2==1: return (pow(a,b-1)*a)%C

print(pow(A,B)%C)

