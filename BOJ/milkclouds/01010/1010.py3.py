
fact=[0,1]
for i in range(2,30): fact.append(fact[i-1]*i)

def c(b,a):
	if a==b: return 1
	return fact[a]//fact[b]//fact[a-b]
 
for i in range(int(input())):
	print(c(*map(int,input().split())))