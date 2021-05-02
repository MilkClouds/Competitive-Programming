k=int(input())

n=0
s=0
while 1:
	n+=1
	s+=1<<n
	if s>=k: break

k-=s-(1<<n)
k-=1
t=bin(k)[2:].replace('1','7').replace('0','4')
print('4'*(n-len(t))+t)