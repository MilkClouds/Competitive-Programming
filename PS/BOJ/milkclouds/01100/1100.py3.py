r=0
for i in range(8):
	r+=input()[i%2::2].count('F')
print(r)