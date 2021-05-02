N=int(input())
d={}
for i in range(N):
    p,c=map(int,input().split())
    d[c]=d.get(c,[])+[p]

result=0

def poss(t):
    if 0<=t<len(pos): return pos[t]
    else: return 10**10

for color,pos in d.items():
    pos.sort()
    if len(pos)==1: continue
    for i,a in enumerate(pos):
        result+=min(abs(poss(i+1)-a),abs(a-poss(i-1)))

print(result)