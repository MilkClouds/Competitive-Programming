s=input()
r=s[::-1]
m=0
for i in range(1,len(r)+1):
	if s.endswith(r[:i]):m=max(m,i)
print(len(s)*2-m)