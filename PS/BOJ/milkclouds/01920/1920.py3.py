input()
dic={}
for i in map(int,input().split()):
	dic[i]=1
input()
for i in map(int,input().split()):
	print(1 if dic.get(i) else 0)