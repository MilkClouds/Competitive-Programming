n=input();i=0
while len(n)>1:
	n=str(sum(map(int,n)));i+=1
print(i)
print('NO' if int(n)%3 else 'YES')