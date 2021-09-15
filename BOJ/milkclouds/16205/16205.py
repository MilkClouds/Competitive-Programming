def camel(S):
    ans = ''
    for i in S:
        ans += i[0].upper() + i[1:]
    return ans[0].lower() + ans[1:]
def pascal(S):
    ans = ''
    for i in S:
        ans += i[0].upper() + i[1:]
    return ans
def snake(S):
    return '_'.join(S)

a, b = input().split()
S = []
if a == '1' or a == '3':
    j = 0
    for i in range(len(b)):
        if b[i].isupper():
            if j == i: continue
            S.append(b[j:i].lower())
            j = i
    S.append(b[j:len(b)].lower())
elif a == '2':
    S = b.split('_')
print(camel(S))
print(snake(S))
print(pascal(S))