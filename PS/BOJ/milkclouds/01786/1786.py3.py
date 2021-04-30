import sys
input=sys.stdin.readline
T=input()[:-1]
P=input()[:-1]
ret=[]
parentSize=len(T)
patternSize=len(P)
def makeTable(pattern):
	table=[0]*patternSize
	j=0
	for i in range(1,patternSize):
		while j>0 and pattern[i]!=pattern[j]:
			j=table[j-1]
		if pattern[i]==pattern[j]:
			j+=1
			table[i]=j
	return table
def KMP(parent,pattern):
	table=makeTable(pattern)
	j=0
	for i in range(parentSize):
		while j>0 and parent[i]!=pattern[j]:
			j=table[j-1]
		if parent[i]==pattern[j]:
			if j==patternSize-1:
				ret.append(i-patternSize+2)
				j=table[j]
			else:
				j+=1
KMP(T,P)
print(len(ret))
print(*ret,sep='\n')