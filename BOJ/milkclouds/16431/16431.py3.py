a,b=map(int,input().split())
c,d=map(int,input().split())
e,f=map(int,input().split())

a=abs(e-a);c=abs(e-c);
b=abs(f-b);d=abs(f-d);
be=max(a,b);
da=c+d;
print('tie' if be==da else ('daisy' if be>da else "bessie"))