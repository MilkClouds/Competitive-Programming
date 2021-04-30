import sys
input=sys.stdin.readline
class TrieNode:
	def __init__(self,valid):
		self.valid=valid
		self.nodes={}
def make(node,string):
	t=string[0]
	if node.nodes.get(t):
		if len(string)==1:
			return 1
		else:
			if node.nodes[t].valid:
				return 1
			return make(node.nodes[t],string[1:])
	else:
		if len(string)==1:
			node.nodes[t]=TrieNode(1)
			return
		node.nodes[t]=TrieNode(0)
		make(node.nodes[t],string[1:])
for _ in range(int(input())):
	n=int(input())
	root=TrieNode(0);flag=0
	for _ in range(n):
		t=input().rstrip()
		if flag:continue
		if make(root,t):
			print("NO")
			flag=1
	flag or print('YES')