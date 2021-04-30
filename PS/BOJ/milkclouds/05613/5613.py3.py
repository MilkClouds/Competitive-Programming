import sys
input=sys.stdin.readline
n=int(input())

while 1:
	i=input().rstrip()
	if i=='=': break
	if i in ('+','-','*','/'): op=i
	else:
		if op=='/': op='//'
		n=eval(str(n)+op+i)
print(n)