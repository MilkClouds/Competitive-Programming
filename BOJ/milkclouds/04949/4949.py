while 1:
    S = input()
    if S == '.': break
    S = ''.join([*filter(lambda x: x in '()[]', S)])
    a = b = 0
    memory = [0] * 123546
    memory2 = [0] * 123546
    for i in S:
        if i == '(':
            a += 1
            memory[a] = b
        elif i == ')':
            if memory[a] != b:
                print('no')
                break
            a -= 1
        elif i == '[':
            b += 1
            memory2[b] = a
        else:
            if memory2[b] != a:
                print('no')
                break
            b -= 1
        if a < 0 or b < 0:
            print('no')
            break
    else:
        if a == 0 and b == 0:
            print('yes')
        else:
            print('no')