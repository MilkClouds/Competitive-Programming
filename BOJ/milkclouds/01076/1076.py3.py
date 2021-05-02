r="""black	0	1
brown	1	10
red	2	100
orange	3	1000
yellow	4	10000
green	5	100000
blue	6	1000000
violet	7	10000000
grey	8	100000000
white	9	1000000000"""

l=[i.split('\t') for i in r.split('\n')]

d={}
for i in l:
    d[i[0]]=i[1:]

#print(d)


print(int( d[input()][0]+d[input()][0]+d[input()][1][1:] ))