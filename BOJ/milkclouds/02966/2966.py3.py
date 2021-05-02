s=('ABC','BABC','CCAABB');ll=(3,4,6);r=[0]*3
input()
answer=input();idx=0
for i in answer:
	for j in range(3):
		if s[j][idx%ll[j]]==i:r[j]+=1
	idx+=1
m=max(r)
print(m)
if(m==r[0]):print("Adrian")
if(m==r[1]):print("Bruno")
if(m==r[2]):print("Goran")