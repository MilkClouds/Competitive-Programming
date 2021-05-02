import sys;input=lambda:sys.stdin.readline().rstrip()
N=int(input())
s=input()
t=input()

start=end=0
for i in s:
    start=start*26+ord(i)-97
for i in t:
    end=end*26+ord(i)-97
mid=(start+end)//2
st=''
while mid:
    st+=chr(97+mid%26)
    mid//=26
st+='a'
print(st[N-1::-1])