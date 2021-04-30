import sys
for line in sys.stdin:
	if line.rstrip()=='0': exit()
	line=map(int,line.split())
	n=next(line);h=list(line)
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