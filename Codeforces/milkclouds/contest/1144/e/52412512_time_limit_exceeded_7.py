k=int(input())
func=lambda x:ord(x)-97
s=list(map(func,input()))
t=list(map(func,input()))

for i in range(k-1,-1,-1):
    s[i]+=t[i]
    if i:
        s[i-1]+=s[i]//26
        s[i]%=26

for i in range(k):
    mod=s[i]%2
    s[i]//=2
    if i!=k-1:
        s[i+1]+=mod*26
ans=''
for i in s:
    ans+=chr(i+97)
print(ans)