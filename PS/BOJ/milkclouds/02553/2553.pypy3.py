def div(n):
    return n if n%10 else div(n//10)
def fact(n):
    ret=1
    for i in range(2,n+1):
        i=div(i)
        ret*=i
        ret=div(ret)
        ret%=1000000
    return ret%10

print(fact(int(input())))