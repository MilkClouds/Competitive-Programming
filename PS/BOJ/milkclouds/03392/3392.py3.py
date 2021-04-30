import sys
input=sys.stdin.readline
sys.setrecursionlimit(99999)

N=int(input())
lines=[]
for _ in range(N):
    x1,y1,x2,y2=map(int,input().split())
    if y1==y2 or x1==x2: continue
    lines.append((x1,y1,y2,1))
    lines.append((x2,y1,y2,-1))
lines.sort(key=lambda x:x[0])
ans=lx=0
class SegTree:
    tree=[0]*120001
    lazy=[0]*120001
    cnt=[0]*120001
    def update(self,node,l,r,s,e,diff):
        if r<s or e<l:
            return
        if s<=l and r<=e:
            self.cnt[node]+=diff
        else:
            m=(l+r)//2
            self.update(node*2,l,m,s,e,diff)
            self.update(node*2+1,m+1,r,s,e,diff)
        if self.cnt[node]:
            self.tree[node]=r-l+1
        else:
            if l==r:
                self.tree[node]=0
            else:
                self.tree[node]=self.tree[node*2]+self.tree[node*2+1]
Seg=SegTree()
for i in range(len(lines)):
    x,y1,y2,flag=lines[i]
    ans+=(x-lx)*Seg.tree[1]
    Seg.update(1,0,30000,y1,y2-1,flag)
    lx=x
print(ans)