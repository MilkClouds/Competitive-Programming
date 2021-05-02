for idx in range(int(input())):
	n=int(input())
	b=input()
	print("Case #%d: "%(idx+1),end='')
	for i in range(n):
		t=int(b[i*8:i*8+8].replace("O",'0').replace('I','1'),2)
		print(chr(t),end='')
	print()