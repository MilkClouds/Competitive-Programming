import sys
if 1:
	n=int(input())
	h=[int(input()) for _ in range(n)]
	stack=[];ret=0
	for i in range(n):
		idx=i
		while stack and stack[-1][0]>=h[i]:
			height,idx=stack.pop()
			ret=max(ret,(i-idx)*height)
		stack.append((h[i],idx))
	while stack:
		height,idx=stack.pop()
		ret=max(ret,(n-idx)*height)
	print(ret)