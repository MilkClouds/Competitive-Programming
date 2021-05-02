import sys
input=sys.stdin.readline

n=int(input())
st={}
m=0;r=0
for i in map(int,input().split()):
	if st.pop(i,0):
		m-=1
	else:
		m+=1
		r=max(r,m)
		st[i]=1
print(r)