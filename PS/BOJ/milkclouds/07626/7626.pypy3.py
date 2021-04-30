import sys
input=sys.stdin.readline
sys.setrecursionlimit(99999)

N=int(input())
lines=[]
yList=[]
rectangles=[]
for _ in range(N):
    x1,x2,y1,y2=map(int,input().split())
    yList.append(y1)
    yList.append(y2)
    rectangles.append((x1,x2,y1,y2))
yList.sort()
dic={}
for idx,i in enumerate(yList):
    dic[i]=idx
for x1,x2,y1,y2 in rectangles:
    lines.append((x1,dic[y1],dic[y2],1))
    lines.append((x2,dic[y1],dic[y2],-1))
lines.sort(key=lambda x:x[0])
ans=lx=0
class SegTree:
    tree=[0]*1200001
    lazy=[0]*1200001
    cnt=[0]*1200001
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
            self.tree[node]=yList[r+1]-yList[l]
        else:
            if l==r:
                self.tree[node]=0
            else:
                self.tree[node]=self.tree[node*2]+self.tree[node*2+1]
Seg=SegTree()
for i in range(len(lines)):
    x,y1,y2,flag=lines[i]
    ans+=(x-lx)*Seg.tree[1]
    Seg.update(1,0,2*N,y1,y2-1,flag)
    lx=x
print(ans)