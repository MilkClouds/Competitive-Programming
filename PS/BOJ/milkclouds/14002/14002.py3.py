from bisect import bisect_left as bl
import sys;input=sys.stdin.readline;print=sys.stdout.write

n = int(input())
L = list(map(int,input().split()))
seq = []; seqlen=0
seqind = []
prev = []

for i in range(n):
    x = L[i]
    pos = bl(seq, x)
    if seqlen <= pos:
        seq.append(x)
        seqlen+=1
        seqind.append(i)
    else:
        seq[pos] = x
        seqind[pos] = i
    if pos == 0:
        prev.append(None)
    else:
        prev.append(seqind[pos-1])

res = []
k = seqind[-1]
while k != None:
    res.append(L[k])
    k = prev[k]
print(str(seqlen)+'\n')
print(' '.join(map(str,reversed(res))))