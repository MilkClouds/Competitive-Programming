for i in range(int(input())):
    A=input()
    stack=0; score=0
    for i in A:
        if i=='O': stack+=1; score+=stack
        else: stack=0
    print(score)