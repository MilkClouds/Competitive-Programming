s=input()
n=len(s);best='z'*50
def f(x):
    return ''.join(reversed(x))
for i in range(1,n):
    for j in range(i+1,n):
        a,b,c=s[:i],s[i:j],s[j:]
        temp=f(a)+f(b)+f(c)
        best=min(best,temp)
print(best)