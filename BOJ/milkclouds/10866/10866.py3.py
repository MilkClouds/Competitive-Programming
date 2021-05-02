from collections import deque
import sys
deck=deque()
input();l=0
for cmd in sys.stdin:
	if cmd[0] == 'b':
		print(deck[l-1] if l else -1)
	elif cmd[0]=='f':
		print(deck[0] if l else -1)
	elif cmd[0]=='e':
		print(0 if l else 1)
	elif cmd[0]=='s':
		print(l if l else 0 )
	else:
		if cmd[5]=='f':
			i=int(cmd.split()[1])
			deck.appendleft(i);l+=1
		elif cmd[5]=='b':
			i=int(cmd.split()[1])
			deck.append(i);l+=1
		else:
			if not l: print(-1); continue
			l-=1
			if cmd[4]=='f':
				print(deck.popleft())
			else:print(deck.pop())