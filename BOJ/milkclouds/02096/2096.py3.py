mDP=[0,0,0]
MDP=[0,0,0]

import sys
input=sys.stdin.readline
act=[(0,1),(0,1,2),(1,2)]
for i in range(int(input())):
	inp=list(map(int,input().split()))
	m=[0]*3
	M=[0]*3
	for e in range(3):
		m[e]=inp[e]+min([mDP[i] for i in act[e]])
	for e in range(3):
		M[e]=inp[e]+max([MDP[i] for i in act[e]])
	mDP=m;MDP=M
print(max(MDP),min(mDP))