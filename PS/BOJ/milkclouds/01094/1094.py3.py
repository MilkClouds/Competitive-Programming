#a,b,c,d=map(int,input().split())

x=int(input()); stick=[64]

while sum(stick)>x:
	r=min(stick)
	for i in range(2):
			stick.append(r//2)
	stick.remove(r)
	for i in range(1):
			if sum(stick)-min(stick)>=x:
				stick.remove(min(stick))

print(len(stick))