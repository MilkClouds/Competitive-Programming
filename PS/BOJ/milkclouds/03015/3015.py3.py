import sys
input = sys.stdin.readline
n = int(input())
stack = []
ans = 0
prev = None
for i in range(n):
    x = int(input())
    while stack and stack[-1][0] < x: ans+= stack.pop()[1]
    if stack and stack[-1][0] == x:
        cnt = stack.pop()[1]
        ans+= cnt
        stack.append((x, cnt+1))
    else: stack.append((x, 1))
    if stack and stack[0][0] > x: ans+= 1
print(ans)