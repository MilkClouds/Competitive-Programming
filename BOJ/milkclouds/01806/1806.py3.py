N,S=map(int,input().split())
A=list(map(int,input().split()))

left=0;right=0;add=A[0];m=10**10
while 1:
	if add>=S:
		if left==right: print(1); exit()
		else: m=min(m,right-left+1)
		add-=A[left]; left+=1
	else:
		if right==N-1: break
		right+=1; add+=A[right]
print(m if m!=10**10 else 0)