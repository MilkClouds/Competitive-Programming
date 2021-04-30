import sys
input=sys.stdin.readline

a,b=map(int,[input(),input()],(2,2))
wow=10**5
 
t=bin(a&b)[2:]
print('0'*(wow-len(t))+t)

t=bin(a|b)[2:]
print('0'*(wow-len(t))+t)

t=bin(a^b)[2:]
print('0'*(wow-len(t))+t)

def at(a):
	return '0' if a=='1' else '1'
t=''.join(list(map(at,bin(a)[2:])))
print('1'*(wow-len(t))+t)

t=''.join(list(map(at,bin(b)[2:])))
print('1'*(wow-len(t))+t)