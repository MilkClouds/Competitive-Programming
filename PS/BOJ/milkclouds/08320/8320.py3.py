n=int(input())

r=set()
for i in range(1,n+1):
	for j in range(1,n//i+1):
		r.add(tuple(sorted((i,j))))

print(len(r))