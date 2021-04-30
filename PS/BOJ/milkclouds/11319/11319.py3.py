v=['a','e','i','o','u']
for _ in range(int(input())):
    s=input().lower()
    ret=0;
    for i in v:
        ret+=s.count(i);
    print(len(s.replace(' ',''))-ret,ret)