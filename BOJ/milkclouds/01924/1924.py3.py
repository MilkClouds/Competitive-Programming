x,y=[int(i) for i in input().split(' ')]

d=[31,28,31,30,31,30,31,31,30,31,30,31]
day=["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

if x==1: n=y%7
else: n=(sum(d[:x-1])+y)%7

print(day[n])