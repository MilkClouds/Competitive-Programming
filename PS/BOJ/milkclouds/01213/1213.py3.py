n=input()

left='';mid=''
for i in range(26):
	c=n.count(chr(65+i))
	if c&1:
		if mid:print("I'm Sorry Hansoo");exit()
		mid=chr(i+65)
		left+=chr(i+65)*(c//2)
	else:
		left+=chr(i+65)*(c//2)

print(left+mid+left[::-1])