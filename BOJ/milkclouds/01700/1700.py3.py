k,n=map(int,input().split())
a=list(map(int,input().split()))

s=set()
ans=0
for i in range(n):
	c=a[i]
	if len(s)<k:
		s.add(c)
	elif c in s:
		continue
	else:
		chk={}
		for j in range(i+1,n):
			if a[j] in s:
				chk.setdefault(a[j],j)
		for i in s:
			if i not in chk:
				chk[i]=1000
		t=max(chk.items(),key=lambda x:x[1])
		s.discard(t[0])
		ans+=1
		s.add(c)
print(ans)