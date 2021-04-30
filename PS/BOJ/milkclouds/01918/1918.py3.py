class Node:
    def __init__(self,value,l=None,r=None):
        self.value=value
        self.l=l;self.r=r
q=input()
def solution(q):
    if not q:
        return None
    if len(q)==1:
        return Node(q)
    par=0
    for i in range(len(q)-1,-1,-1):
        if q[i]=='(':
            par-=1
        elif q[i]==')':
            par+=1
        if par==0 and q[i] in ('+','-'):
            return Node(q[i],solution(q[:i]),solution(q[i+1:]))
    par=0
    for i in range(len(q)-1,-1,-1):
        if q[i]=='(':
            par-=1
        elif q[i]==')':
            par+=1
        if par==0 and q[i] in ('*','/'):
            return Node(q[i],solution(q[:i]),solution(q[i+1:]))
    return solution(q[1:-1])

tree=solution(q)

def postorder(node):
    if node==None:return
    postorder(node.l)
    postorder(node.r)
    print(node.value,end='')
postorder(tree)