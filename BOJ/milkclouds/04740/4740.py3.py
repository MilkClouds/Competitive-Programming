def f():
  global s
  s=input()
  return s
while f()!='***':
  print(s[::-1])