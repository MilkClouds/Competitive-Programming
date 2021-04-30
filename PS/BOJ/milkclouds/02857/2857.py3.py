s=1
for i in range(5):
	if 'FBI' in input():
		print(i+1,end=' ' if i!=4 else '');s=0
if s:print('HE GOT AWAY!')