t=input()
n=0
for i in t:
	if ord(i)>96:n+=ord(i)-96
	else:n+=ord(i)-64+26
for i in range(2,n):
	if n%i==0:
		print('It is not a prime word.')
		exit()
print('It is a prime word.')