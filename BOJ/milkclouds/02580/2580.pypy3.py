maze=[list(map(int,input().split()))for _ in range(9)]
xset=[set()for _ in range(9)]
yset=[set()for _ in range(9)]
nine=[set()for _ in range(9)]
get=[[i//3*3+j//3 for j in range(9)]for i in range(9)]
empty=[]
for i in range(9):
    for j in range(9):
        if maze[i][j]==0:
            empty.append((i,j))
        else:
            xset[i]|={maze[i][j]}
            yset[j]|={maze[i][j]}
            nine[get[i][j]].add(maze[i][j])
totset=set(range(1,10))
def solution(c):
    if len(empty)==c:
        [print(*maze[i]) for i in range(9)]
        exit()
    i,j=empty[c]
    for candidate in totset^(xset[i]|yset[j]|nine[get[i][j]]):
        maze[i][j]=candidate
        xset[i]|={candidate}
        yset[j]|={candidate}
        nine[get[i][j]].add(candidate)
        solution(c+1)
        xset[i].discard(candidate)
        yset[j].discard(candidate)
        nine[get[i][j]].discard(candidate)

solution(0)