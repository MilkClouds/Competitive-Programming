n=int(input());r=0
for a in range(1,501):
	b2=a*a+n
	if b2<=250000 and int(b2**.5)**2==b2:
		r+=1
print(r)