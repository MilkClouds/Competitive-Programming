import sys
input=sys.stdin.readline

class node:
	def __init__(self,idx):
		self.idx=idx
	def __str__(self):
		return chr(65+self.idx)


N=int(input())
nodes={}
for i in range(N):
	nodes[chr(i+65)]=node(i)
nodes['.']=None

for _ in range(N):
	n,l,r=input().split()
	nodes[n].leftC=nodes[l]
	nodes[n].rightC=nodes[r]

def preorder(current):
	if current==None: return
	print(current,end='')
	preorder(current.leftC)
	preorder(current.rightC)

def inorder(current):
	if current==None: return
	inorder(current.leftC)
	print(current,end='')
	inorder(current.rightC)

def postorder(current):
	if current==None: return
	postorder(current.leftC)
	postorder(current.rightC)
	print(current,end='')

preorder(nodes['A'])
print()
inorder(nodes['A'])
print()
postorder(nodes['A'])