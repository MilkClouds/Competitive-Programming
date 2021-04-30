maze=[list(map(int,input().split()))for _ in range(9)]
xset=[[False]*10 for _ in range(9)]
yset=[[False]*10 for _ in range(9)]
nine=[[False]*10 for _ in range(9)]
get=[[i//3*3+j//3 for j in range(9)]for i in range(9)]
empty=[]
for i in range(9):
    for j in range(9):
        if maze[i][j]==0:
            empty.append((i,j))
        else:
            xset[i][maze[i][j]]=True
            yset[j][maze[i][j]]=True
            nine[get[i][j]][maze[i][j]]=True

def solution(c):
    if len(empty)==c:
        [print(*maze[i]) for i in range(9)]
        exit()
    i,j=empty[c]
    for candidate in range(1,10):
        if xset[i][candidate] or yset[j][candidate] or nine[get[i][j]][candidate]:continue
        maze[i][j]=candidate
        xset[i][candidate]=yset[j][candidate]=nine[get[i][j]][candidate]=True
        solution(c+1)
        xset[i][candidate]=yset[j][candidate]=nine[get[i][j]][candidate]=False

solution(0)