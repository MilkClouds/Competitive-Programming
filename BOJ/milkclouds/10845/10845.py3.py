import sys
from collections import deque
input=sys.stdin.readline
queue=deque()
for i in range(int(input())):
	cmd=input()
	if cmd[1]=="o":
		if queue: print(queue.popleft())
		else: print(-1)
	elif cmd[0]=="s":
		print(len(queue))
	elif cmd[0]=="e":
		print(0 if queue else 1)
	elif cmd[0]=="f":
		print(queue[0] if queue else -1)
	elif cmd[0]=="b":
		print(queue[-1] if queue else -1)
	else:
		queue.append(cmd.split(' ')[1].rstrip())