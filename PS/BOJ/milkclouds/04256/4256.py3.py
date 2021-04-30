import sys
input=sys.stdin.readline

inp='''2
4
3 2 1 4
2 3 4 1
8
3 6 5 4 8 7 1 2
5 6 8 4 3 1 2 7'''
inp=iter(inp.split('\n'))
#input=lambda:next(inp)

def solution(preorder,inorder):
	n=len(preorder)
	if preorder==[]:
		return
	root=preorder[0]
	left=inorder.index(root)
	right=n-left-1
	solution(preorder[1:left+1], inorder[:left])
	solution(preorder[left+1:], inorder[left+1:])
	print(root,end=' ')

for _ in range(int(input())):
	n=int(input())
	preorder=list(map(int,input().split()))
	inorder=list(map(int,input().split()))
	solution(preorder,inorder)
	print()
