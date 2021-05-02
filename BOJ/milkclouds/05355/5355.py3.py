for i in range(int(input())):
 x=input().split()
 num=float(x[0])
 for i in x[1:]:
  if i=='@': num*=3
  elif i=='%': num+=5
  elif i=='#': num-=7
 print('%.2f'%num)