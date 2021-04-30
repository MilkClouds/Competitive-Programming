N=int(input())
f=lambda N:('s' if N>1 else '')
for i in range(N+1):
	i=N-i
	if i>1:
		print("%d bottle%s of beer on the wall, %d bottle%s of beer.\n\
Take one down and pass it around, %d bottle%s of beer on the wall."%(i,f(i),i,f(i),i-1,f(i-1)))
	elif i==1:
		print("1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.")
	else:
		print("No more bottles of beer on the wall, no more bottles of beer.\n\
Go to the store and buy some more, %d bottle%s of beer on the wall."%(N,'s' if N>1 else ''))
	print()