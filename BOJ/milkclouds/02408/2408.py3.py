s=''
for _ in range(int(input())*2-1):
	s+=input()
print(eval(s.replace('/','//')))