n=int(input())
def score(sc):
    if sc>96:return 'A+'
    if sc>=90:return 'A'
    if sc>86:return 'B+'
    if sc>=80:return 'B'
    if sc>76:return 'C+'
    if sc>=70:return 'C'
    if sc>66:return 'D+'
    if sc>=60:return 'D'
    return 'F'
for _ in range(n):
    s,sc=input().split()
    print(s,score(int(sc)))