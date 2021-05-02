s=input().split('-')
eva=lambda y:sum(int(x.lstrip('0') if x.lstrip('0') else '0') for x in y.split('+'))
print(eva(s[0])-sum(eva(i) for i in s[1:]))