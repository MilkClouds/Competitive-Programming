import re

for i in range(int(input())):
    S=input()
    t=re.match('^(.*?)://(.*?)(:(.*?))?(/(.*?))?$', S)
    t=[t[i] for i in range(7)]
    for j in range(7):
        if t[j]==None:
            t[j]='<default>'
    print("URL #%d"%(i+1))
    print("Protocol = %s"%t[1])
    print("Host     = %s"%t[2])
    print("Port     = %s"%t[4])
    print("Path     = %s"%t[6])
    print()
