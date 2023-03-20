import sys
sys.setrecursionlimit(10 ** 6)
input = lambda: sys.stdin.readline()[:-1]
A, B = map(int, input().split())
treeA = []; treeB = []
def insert(tree, string):
    if not string:
        return tree
    if not tree:
        tree = [[] for _ in range(26)]
    k = ord(string[0]) - 97
    tree[k] = insert(tree[k], string[1:])
    return tree
def query(tree, string):
    if not string or not tree:
        return 0
    k = ord(string[0]) - 97
    return query(tree[k], string[1:]) + 1

p1 = 31
p2 = 37
m1 = 10**9 + 9
m2 = 10**9 + 7
i1 = pow(p1, m1 - 2, m1)

def compute_hashes(s):
    return (ord(s[-1]) - 96 + compute_hashes(s[:-1]) * p1) % m1 if s else 0

treeA = {}; treeB = {}
for a in range(A):
    # treeA = insert(treeA, input())
    treeA[compute_hashes(input())] = 1
for b in range(B):
    treeB[compute_hashes(input()[::-1])] = 1
for _ in range(int(input())):
    s = input()
    sr = s[::-1]
    # print("Yes" if query(treeA, s) + query(treeB, s[::-1]) >= len(s) else "No")
    l = 0; r = compute_hashes(sr)
    for i in range(len(s)):
        l = (l * p1 + (ord(s[i]) - 96)) % m1
        r = (r - (ord(s[i]) - 96)) * i1 % m1
        if treeA.get(l) and treeB.get(r):
            print("Yes")
            break
    else:
        print("No")
    # print("Yes" if query(treeA, s) + query(treeB, s[::-1]) >= len(s) else "No")