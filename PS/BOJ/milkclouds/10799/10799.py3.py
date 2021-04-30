import sys
st=0;t=0;ret=0
for i in sys.stdin.readline().rstrip():
	if i=='(':
		st+=1;t=1
	else:
		st-=1
		if t:ret+=st
		else:ret+=1
		t=0
print(ret)