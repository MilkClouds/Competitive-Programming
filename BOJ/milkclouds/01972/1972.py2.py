while True:
    x=raw_input()
    if x=='*': break
    ans = True
    for i in xrange(1,len(x)):
        s=set()
        for j in xrange(len(x)-i):
            if x[j]+x[j+i] in s:
                ans = False
                break
            else:
                s.add(x[j]+x[j+i])
        if not ans: break
    print x,'is',
    if not ans: print 'NOT',
    print 'surprising.'