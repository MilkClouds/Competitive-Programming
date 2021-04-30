a=['A','B','C',"D",'E']
for _ in range(3):
	r=input().split().count('0')
	if r==0: r=5
	r-=1
	print(a[r])