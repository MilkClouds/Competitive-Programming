prev=0
st=input()
h=0
for i in st:
	if i==prev:h+=5
	else:h+=10
	prev=i
print(h)