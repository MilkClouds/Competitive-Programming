a,b=map(int,input().split())
if b==1:
    print('INFINITE' if a<0 else 0)
    exit()
if b&1: print('ERROR');exit()

b=b//2
if b==0:
	if a>0:print("INFINITE")
	else: print(0)
	exit()

print(len(range(a-b,0,-b)))