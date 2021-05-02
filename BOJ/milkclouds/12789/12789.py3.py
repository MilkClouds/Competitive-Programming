N=int(input())
def q(): return queue[0] if queue else -1
def s(): return stack[-1] if stack else -1

queue=list(map(int,input().split()))
stack=[]

index=1
while index<=N:
	if q()==index: queue.pop(0); index+=1
	else:
		if s()==index: stack.pop(); index+=1
		else:
			if not queue: print('Sad'); exit()
			stack.append(queue.pop(0))
print("Nice")