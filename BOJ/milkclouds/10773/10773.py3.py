a=[]
def e(i): a.append(i) if i else a.pop()
[e(int(input())) for i in range(int(input()))]
print(sum(a))