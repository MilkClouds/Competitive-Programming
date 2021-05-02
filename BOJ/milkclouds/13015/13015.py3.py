n=int(input())
W=4*n-3
H=2*n-1
const=[[' ']*H for i in range(W)]
for i in range(n):
	const[i][0]='*'
	const[W-i-1][0]='*'
	const[i][H-1]='*'
	const[W-i-1][H-1]='*'
	const[i][i]='*'
	const[n+i-1][i]='*'
	const[W-i-1][i]='*'
	const[W-i-n][i]='*'
	const[W-i-1][H-i-1]='*'
	const[W-i-n][H-i-1]='*'
	const[i][H-i-1]='*'
	const[n+i-1][H-i-1]='*'
for i in zip(*const):
	print(''.join(i).rstrip())
