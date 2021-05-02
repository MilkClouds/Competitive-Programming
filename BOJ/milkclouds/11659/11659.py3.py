import sys
input=sys.stdin.readline

class SegmentTree:
	def __init__(self,value):
		self.left,self.right=0,len(value)-1
		self.value=value
		self.tree=[0]*(len(value)*4)
		stack=[(1,self.left,self.right)]
		while stack:
			index,start,end = stack.pop()
			self.tree[index]=sum(value[start:end+1])
			if start < end:
				mid=(start+end)//2
				stack.append((index*2,start,mid))
				stack.append((index*2+1,mid+1,end))

	def query(self,left,right):
		stack=[(1,self.left,self.right)]; ret=0
		while stack:
			index,start,end = stack.pop()
			if left<=start and end<=right: ret += self.tree[index]
			# elif start==end: continue
			elif end<left or start>right: continue
			else:
				mid=(start+end)//2
				stack.append((index*2,start,mid))
				stack.append((index*2+1,mid+1,end))
		return ret

	# def change()

N,M=map(int,input().split())
# value=[int(input()) for i in range(N)]
value=list(map(int,input().split()))
seg=SegmentTree(value)

for _ in range(M):
	i,j=map(int,input().split())
	print(seg.query(i-1,j-1))