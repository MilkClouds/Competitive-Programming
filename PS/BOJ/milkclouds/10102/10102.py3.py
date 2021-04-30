n=int(input())
t=input().count('A')
print('B' if n-t>t else ('Tie' if n-t==t else 'A'))
