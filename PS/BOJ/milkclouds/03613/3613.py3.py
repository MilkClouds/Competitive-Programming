st=input()

if st.startswith('_') or st.endswith('_') or st.count('__'):
	print("Error!");exit()
if st.lower()==st and st.count('_'):
	c=st
	for i in range(len(st)-1):
		if st[i] =='_':
			c=c.replace(st[i:i+2],st[i+1].upper())
	print(c)

elif not st.count('_') and st[0].lower()==st[0]:
	c=st
	for i in st:
		if i<='Z':
			c=c.replace(i,'_'+i.lower())
	print(c)
else: print('Error!')
	