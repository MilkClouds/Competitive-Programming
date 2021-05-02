import sys
input = sys.stdin.readline

#정답 비율 = (문제를 맞은 사람의 수) / (문제를 맞은 사람의 수 + (문제를 맞은 각 사람이 그 문제를 맞기 전까지 틀린 횟수의 총 합)) × 100

N=int(input())
correct=set()
killed={}

for i in range(N):
    l=input().split(' ')
    if l[1]=='megalusion': continue
    if l[2]=='4':
        correct.add(l[1])
    else:
        if not correct&{l[1]}:
            killed[l[1]]=killed.get(l[1],0)+1

numerator=len(correct)
denominator=len(correct)+sum([killed.get(i,0) for i in correct])

try: r=numerator/denominator*100
except: r=0
print(r)