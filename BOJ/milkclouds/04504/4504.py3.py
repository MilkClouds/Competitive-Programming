import sys
input=sys.stdin.readline

n=int(input())
arr=[n]
for i in range(1,n//2+1):
	if n%i==0: arr.append(i)
while 1:
	i=int(input())
	if i==0: break
	if i%n==0:
		print('%d is a multiple of %d.'%(i,n))
	else:print('%d is NOT a multiple of %d.'%(i,n))