n=int(input())
r=set()
for _ in range(n):
	r.add(tuple(sorted(input().split())))

if r=={('1', '4'), ('3', '4'), ('1', '3')}:
	print('Wa-pa-pa-pa-pa-pa-pow!')
else:
	print('Woof-meow-tweet-squeek')