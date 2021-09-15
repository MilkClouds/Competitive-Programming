from math import *

def s(x):
  a = 0
  while x:
    a += x % 10
    x //= 10
  return a

import sys
input = sys.stdin.readline
for i in range(int(input())):
  n = int(input())
  while 1:
    if gcd(n, s(n)) > 1:
      print(n)
      break
    n += 1
