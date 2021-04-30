n=input()
if set(n)-set("2018"):
    print(0)
else:
    if set("2018")-set(n):
        print(1)
    else:
        r=[n.count(i) for i in "2018"]
        if len(set(r))==1:
            print(8)
        else:
            print(2)


