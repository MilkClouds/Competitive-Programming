def G(a,b):
 if a<b: a,b=b,a
 if a%b==0: return b
 return G(a%b,b)
def L(a,b):
 return a*b//G(a,b)
a,b=[int(i) for i in input().split(' ')]
q=G(a,b)
print('1'*q)