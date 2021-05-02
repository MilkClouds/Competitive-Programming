from bisect import *
from collections import deque
import sys;input=sys.stdin.readline
sortedArray=[]
N,K=map(int,input().split())
A=[int(input()) for i in range(N)]
def process(num):
	insort(sortedArray,num)
def remove(num):
	sortedArray.pop(bisect(sortedArray,num)-1)
ret=0;kk=(K+1)//2-1
for i in range(N):
	process(A[i])
	if i<K-1:continue
	if i>=K:
		remove(A[i-K])
	ret+=sortedArray[kk]
print(ret)