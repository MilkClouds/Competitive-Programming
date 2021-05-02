while exec("i=input().split()") or i!="# 0 0".split():
    print(i[0],"Senior" if int(i[1])>17 or int(i[2])>79 else 'Junior')