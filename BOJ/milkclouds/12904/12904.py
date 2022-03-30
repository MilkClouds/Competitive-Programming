S, T = input(), input()
A = [0] * (len(T) + 1)
Ss = S.count("B")
sub = T.count("B") - Ss
if sub < 0:
    print(0)
    exit()
if sub & 1:
    T = T[::-1]
s = -1
e = len(T)
for i in range(len(T) + 1):
    if i: A[i] = A[i - 1] + (T[i - 1] == 'B')
    if A[i] == (sub + 1 >> 1) and s == -1:
        s = i
    if A[i] == (sub + 1 >> 1) + Ss + 1 and e == len(T):
        e = i - 1
t = T[s:e]
if len(S) <= len(t) and S.rstrip('A') == t.rstrip('A'):
    print(1)
else:
    print(0)