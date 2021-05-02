c=0
for i in range(int(input())):
	c+=1 if input()=='0' else -1

print("Junhee is not cute!" if c>0 else  "Junhee is cute!")