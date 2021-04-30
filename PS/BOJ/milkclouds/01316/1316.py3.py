tot=0
for i in range(int(input())):
	s=input()
	dic=[0]*26; past=1; no=0
	for i in s:
		dic[ord(i)-97]+=1
		if (past!=i) and (dic[ord(i)-97]!=1): no=1; break
		past=i
	tot+=0 if no else 1
print(tot)