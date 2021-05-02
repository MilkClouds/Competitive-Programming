i=lambda:int(input())

A=i()*3+i()*2+i()
B=i()*3+i()*2+i()
print("A" if A>B else ("B" if A<B else "T"))