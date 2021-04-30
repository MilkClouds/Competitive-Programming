from bisect import bisect_left as bl
import sys;input=sys.stdin.readline;print=sys.stdout.write

n = int(input())
L = list(map(int,input().split()))
seq = []; seqlen=0

for i in range(n):
    x = L[i]
    pos = bl(seq, x)
    if seqlen <= pos:
        seq.append(x)
        seqlen+=1
    else:
        seq[pos] = x

print(str(seqlen)+'\n')