v,w,d=map(int,input().split())

current=0;ret=0;horiz=v

while 1:
	time=w/horiz
	current+=5*time**2
	if current>d:break
	horiz*=0.8
	ret+=1

print(ret)