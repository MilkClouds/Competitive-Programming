#input=open('python.in').readline

bas=input().rstrip()
d='LOVE'
t={}
for i in d:
	t[i]=bas.count(i)
x=0
y='a'
for _ in range(int(input())):
	st=input().rstrip()
	for i in d:
		exec(i+'=t["'+i+'"]+'+str(st.count(i)))
	a=eval('((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100')
	if a>x:
		x=a
		y=st
	elif a==x:
		y=sorted([y,st])[0]
print(y)