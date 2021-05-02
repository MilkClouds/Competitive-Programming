n=input()
s=input()
mod=1234567891
def hash(s):
   ret=0
   for i,j in enumerate(s):
      ret+=(ord(j)-96)*pow(31,i,mod)
      ret%=mod
   return ret
print(hash(s))