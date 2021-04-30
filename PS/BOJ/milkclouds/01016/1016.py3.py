m,M=[int(i) for i in input().split(' ')]

limit=int(M**0.5)
arr=[1]*(limit+1); pn=[2];

for i in range(3,limit+1,2):
	if not arr[i]: continue
	pn.append(i)
	for e in range(i**2,limit+1,i*2):
		arr[e]=0

"""
for index in range(3,int(M**0.5)+1,2):
	if index not in (2,3):
		if index%6 not in (1,5): continue
		for i in pn:
			if index//i==0: continue
	pn.append(index)

print(time.time()-lt)
"""

arr=[1]*(M-m+1)
for index in pn:
	num=index**2
	for i in range(m//num+1 if m%num else m//num,M//num+1):
		arr[num*i-m]=0
print(arr.count(1))
