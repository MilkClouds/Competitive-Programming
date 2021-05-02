t=input()
vowel=('a','e','i','o','u')
mute=0
for i in t:
	if mute==0:print(i,end='')
	if (i in vowel) and (mute==0):
		mute=2
	else:
		mute=mute-1 if mute>0 else 0