from collections import deque
N,M=map(int,input().split())
deq=deque(range(1,N+1));size=N;cnt=0
for i in map(int,input().split()):
    while 1:
        pos=deq.index(i)
        if pos==0:
            deq.popleft()
            size-=1
            break
        left=pos
        right=size-pos-1
        if left>right:
            deq.appendleft(deq.pop())
            cnt+=1
        else:
            deq.append(deq.popleft())
            cnt+=1
print(cnt)